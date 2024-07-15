import sys

from lib import switcher_pedal_plots, wave2data


infile = sys.argv[1]
minx = float(sys.argv[2])
maxx = float(sys.argv[3])

#wave2data.create_datafile(infilename=infile)

switcher_pedal_plots.plot_signal(
    infilename=wave2data.data_filename_from_wave_filename(infilename=infile),
    minx=minx,
    maxx=maxx
)
