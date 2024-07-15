import sys
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv(
    sys.argv[1],
    skiprows=1,
    #header=0,
    names=["time", "kick", "snare", "kick_int", "snare_int", "kick_schmidt", "snare_schmidt"],
    index_col=False,
    #dtype=np.float64
)


df['snare'] = df['snare'] + 1.0
df['snare_int'] = df['snare_int'] + 1.0
df['snare_schmidt'] = df['snare_schmidt'] + 1.0
 

min_t = df['time'].min()
max_t = df['time'].max()
if len(sys.argv) > 2:
    min_t = float(sys.argv[2])
    max_t = float(sys.argv[3])

print(df.head)
df_melt = df[
    (min_t < df['time']) & (df['time'] < max_t)
].melt("time", var_name="cols", value_name="Signal")
print(df_melt.head) 

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
    x="time",
    y="Signal",
    hue="cols",
    errorbar=None
)
print("showing")

plt.show()