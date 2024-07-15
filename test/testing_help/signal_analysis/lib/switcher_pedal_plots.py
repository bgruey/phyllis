import math
import pandas
import seaborn
import struct
from matplotlib import pyplot


def read_data_file(infilename: str) -> tuple:
    with open(infilename, "rb") as infile:
        sample_rate = struct.unpack("<i", infile.read(4))[0]
        data_len = struct.unpack("<i", infile.read(4))[0]
        print(f"Reading {data_len} with {sample_rate}")
        data = struct.unpack(f"<{data_len}d", infile.read(8 * data_len))
        return sample_rate, data
    

def low_pass(data: tuple, dt: float, rc: float):
    alpha = dt / (rc + dt)
    data[0] = alpha * data[0]
    for i in range(1, len(data)):
        data[i] =  data[i-1] + alpha * (data[i] - data[i -1])
    return data
    

def shunted_integrator(data: tuple, dt: float, rc: float):
    y_int = 0.0
    scale_by = math.exp(-dt / rc)
    ret = low_pass(data=data, dt=dt, rc=rc)
    for i, d in enumerate(data):
        ret[i] = y_int * scale_by + abs(d) * dt
        y_int = ret[i]
    return ret # [e * 5.0e3 for e in ret]


def plot_signal(infilename: str, minx: float = None, maxx: float = None):
    sample_size, data = read_data_file(infilename=infilename)
    dt = 1.0 / sample_size

    df = pandas.DataFrame({
        'time': [dt * i for i in range(len(data))],
        'raw': data,
        'abs': [abs(e) for e in data],
        'dc_val': shunted_integrator(
                data=list(data), 
                dt=(1.0 / sample_size),
                rc=(1.0e-6 * 1.0e3)
            )
    })

    if minx is not None and maxx is not None:
        df = df[df['time'].between(minx, maxx)]

    seaborn.lineplot(
        x='time', y='raw',
        data=df
    )
    seaborn.lineplot(
        x='time', y='abs',
        data=df
    )
    seaborn.lineplot(
        x='time', y='dc_val',
        data=df
    )
    pyplot.show()