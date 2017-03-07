# C++ Interface to Matplotlib

## Principles

- `plt::plot(...)` automatically creates a new figure
- `plt::show()` shows the results of the plot
- calls to `plt::plot(...)` go to the same plot until `plt::show()` is called
- by default, calls to `plt::show()` are blocking and execution continues only after the plot window is closed

## Simple plot of a vector:
```
// Std Vector:
std::vector<double> v({1, 2, 3, 4});
plt::plot(v);
plt::show();

// Eigen Types:
VectorX w(100);
w.setRandom();
plt::plot(w)
plt::show();
```

## Plot x and y
```
VectorX t(100);
t.setLinSpaced(100, 0, 20);
VectorX v(100);
v.setRandom();
plt::plot(t, v);
plt::show();
```

## Subplots
```
plt::subplot(3, 1, 1);
plt::plot(v1);
plt::subplot(3, 1, 2);
plt::plot(v2);
plt::subplot(3, 1, 3);
plt::plot(v2);
plt::plot();
```

## Histogram

The histogram function only exposes the `bins`, `data` and `type` parameters of matplotlibs histogram function.
```
plt::hist(v, 10, "bar");
plt::show();
```

## Formatting

All functions accept optional format arguments (`plt::plot(x, y, format)` or `plt::plot(y, format)`). The
expected format strings are equivalent to the matplotlib format strings:
```
plt::plot(t, v, "rx"); // red x'es
plt::show();
```

## Multiple open Plots

`plt::show(false)` opens a non-blocking window. You have to open a new figure to get a second plot ( `plt::figure()`).
The final figure should be opened in blocking mode to keep all windows open.

```
plt::plot(v1);
plt::show(false); // show non-blocking

...

plt::figure(); // new figure
plt::plot(v2)
plt::show(false); // open non-blocking

...

plt::figure();
plt::plot(v3);
plt::show(); // blocking to keep figures 1-3 open.


```

`plt::figure()` accepts a string argument that labels / identifies a specific plot. 

## Style and Labels

```
plt::plot(t, x);
plt::xlabel("time [s]");
plt::ylabel("Position [m]");
plt::title("Position over time");
plt::xlim(t_start, t_end);
plt::ylim(0, x_max);
```
# plotty
