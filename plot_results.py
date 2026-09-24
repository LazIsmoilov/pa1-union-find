import csv
import matplotlib.pyplot as plt

sizes, naive, optimized = [], [], []

with open("results.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        sizes.append(int(row["n"]))
        naive.append(float(row["naive_ms"]))
        optimized.append(float(row["optimized_ms"]))

plt.figure(figsize=(8, 5))
plt.plot(sizes, naive, marker="o", label="Naive (no compression/rank)")
plt.plot(sizes, optimized, marker="o", label="Path compression + union by rank")
plt.xlabel("n (number of vertices)")
plt.ylabel("Time (ms)")
plt.title("Kruskal's MST: Naive vs Optimized Union-Find")
plt.legend()
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig("benchmark_plot.png", dpi=150)
print("Saved benchmark_plot.png")