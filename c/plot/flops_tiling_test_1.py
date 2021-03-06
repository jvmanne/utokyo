import os
import json
import matplotlib.pyplot as plt

dir_current = os.path.dirname(__file__)
dir_data_rel = "../out/flops_tiling_test.txt"
dir_data = os.path.join(dir_current, dir_data_rel)

data_json = json.load(open(dir_data, "r"))
del data_json["end"]
data = {int(k): v["opt_block_size"] for k, v in data_json.items()}

plt.plot(*zip(*sorted(data.items())))
plt.title("FLOPS tiling test - Optimal block size")
plt.xlabel("Matrix size")
plt.ylabel("Optimal block size")

dir_plot_rel = "flops_tiling_test_1.png"
dir_plot = os.path.join(dir_current, dir_plot_rel)
plt.savefig(dir_plot)

