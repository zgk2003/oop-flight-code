import matplotlib.pyplot as plt
import csv
  
time = []
mag_x = []
mag_y = []
mag_z = []
vertical_lines = []
  
with open('3000ms.csv', newline='') as f:
    reader = csv.reader(f)
    data = list(reader)

    for i in range(len(data)-2):
        if data[i][1] == "ON" and  data[i+1][1] == "OFF":
            vertical_lines = vertical_lines + [float(data[i][0])]
      
    for row in data:
        time.append(float(row[0]))
        mag_x.append(float(row[2]))
        mag_y.append(float(row[3]))
        mag_z.append(float(row[4]))
  
fig, ax = plt.subplots(figsize=(12, 6))

ax.plot(time, mag_x, label = "X")
ax.plot(time, mag_y, label = "Y")
ax.plot(time, mag_z, label = "Z")

ax.vlines(vertical_lines, -.25, 1.5, linestyles='dashed', colors='red')

plt.xlabel('Time (ms)')
plt.title('Magnetorquer Magnetometer Readings 3ms On 3ms Off')
plt.legend()
plt.show()