import sys
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv(
    sys.argv[1],
    skiprows=1,
    #header=0,
    names=["time", "kick", "snare", "kick_int","kick_schmidt", "snare_int", "snare_schmidt"],
    index_col=False,
    dtype=np.float64
)

print(df.columns)



df['snare'] = df['snare'] + 1.0
print(df['snare schmidt'])
df['snare_int'] = df['snare_int'] + 1.0
df['snare_schmidt'] = df['snare_schmidt'] + 1.0
 

min_t = df['time'].min()
max_t = df['time'].max()
if len(sys.arg) > 2:
    min_t = float(sys.argv[2])
    max_t = float(sys.argv[3])

df_melt = df[
    (min_t < df['time']) & (df['time'] < max_t)
].iloc[1:].melt("time", var_name="cols", value_name="Signal")
 

# if len(sys.argv) < 3:
#     stch = None
# else:
#     stch = sys.argv[2]
# if stch == "b":
    
# elif stch == "k":
#     df_melt = df[(9.8 < df['Time']) & (df['Time'] < 10.05)].iloc[1:].melt("Time", var_name="cols", value_name="Signal")
# else:
#     df_melt = df.iloc[1:].melt("Time", var_name="cols", value_name="Signal")

print("df melted")
ax = sns.lineplot(
    data=df_melt,
    x="Time",
    y="Signal",
    hue="cols",
    errorbar=None
)
print("showing")

plt.show()