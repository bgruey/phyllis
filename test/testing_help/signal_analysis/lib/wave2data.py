import librosa
import struct


def data_filename_from_wave_filename(infilename: str) -> str:
    return infilename.replace(".wav", ".dat")


def create_datafile(
        infilename: str,
        outfilename: str = None,
        sample_rate_in: int = None
):
    data, sample_rate = librosa.load(
        infilename,
        sr=sample_rate_in
    )

    if outfilename is None:
        outfilename = data_filename_from_wave_filename(infilename=infilename)

    with open(outfilename, "wb") as outfile:
        outfile.write(struct.pack("<i", sample_rate))
        outfile.write(struct.pack("<i", len(data)))
        outfile.write(struct.pack(f"<{len(data)}d", *data))
        print(f"Wrote {len(data)} with sample rate {sample_rate}")