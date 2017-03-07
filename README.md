# Plotty: C++ Interface to Matplotlib
![image](https://cloud.githubusercontent.com/assets/5616392/23658485/10cd0098-0343-11e7-95b5-46d899d6d70e.png)

## Principles

- `plotty::plot(...)` automatically creates a new figure
- `plotty::show()` shows the results of the plot
- calls to `plotty::plot(...)` go to the same plot until `plotty::show()` is called
- by default, calls to `plotty::show()` are blocking and execution continues only after the plot window is closed

## Simple plot of a vector:
```c++
// Std Vector:
std::vector<double> v({1, 2, 3, 4});
plotty::plot(v);
plotty::show();

// Eigen Types:
Eigen::VectorXd w(100);
w.setRandom();
plotty::plot(w)
plotty::show();
```

## Plot x and y
```c++
Eigen::VectorXd t(100);
t.setLinSpaced(100, 0, 20);
Eigen::VectorXd v(100);
v.setRandom();
plotty::plot(t, v);
plotty::show();
```

## Subplots
```c++
plotty::subplot(3, 1, 1);
plotty::plot(v1);
plotty::subplot(3, 1, 2);
plotty::plot(v2);
plotty::subplot(3, 1, 3);
plotty::plot(v2);
plotty::plot();
```

## Histogram

The histogram function only exposes the `bins`, `data` and `type` parameters of matplotlibs histogram function.
```c++
plotty::hist(v, 10, "bar");
plotty::show();
```

## Formatting

All functions accept optional format arguments (`plotty::plot(x, y, format)` or `plotty::plot(y, format)`). The
expected format strings are equivalent to the matplotlib format strings:
```c++
plotty::plot(t, v, "rx"); // red x'es
plotty::show();
```

## Multiple open Plots

`plotty::show(false)` opens a non-blocking window. You have to open a new figure to get a second plot ( `plotty::figure()`).
The final figure should be opened in blocking mode to keep all windows open.

```c++
plotty::plot(v1);
plotty::show(false); // show non-blocking

...

plotty::figure(); // new figure
plotty::plot(v2)
plotty::show(false); // open non-blocking

...

plotty::figure();
plotty::plot(v3);
plotty::show(); // blocking to keep figures 1-3 open.


```

`plotty::figure()` accepts a string argument that labels / identifies a specific plot. 

## Style and Labels

```c++
plotty::plot(t, x);
plotty::xlabel("time [s]");
plotty::ylabel("Position [m]");
plotty::title("Position over time");
plotty::xlim(t_start, t_end);
plotty::ylim(0, x_max);
```
