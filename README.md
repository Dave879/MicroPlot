# MicroPlot

The microcontroller side of the [ArduPlot](https://github.com/Dave879/ArduPlot) protocol

An example is present under ```src/main.cpp```

Tested with:
 - Raspberry Pi Pico
 - Teensy 4.1
 - Atmega 328P

But it should be compatible with any microcontroller running the Arduino framework.

## Usage

Copy and include `ArduPlot.h` inside your project (available under `include/ArduPlot.h`), no extra dependencies needed.

To enable the functions, you must `#define ARDUPLOT_DEBUG true` before the `#include`:

``` cpp
#define ARDUPLOT_DEBUG true
#include "ArduPlot.h"
```

### Draw a line graph

``` cpp
ArduPlot::LineGraph(String title, double value)
```

or, if you want a more optimized function, but the `title` needs to be a string literal:

``` cpp
ARDUPLOT_LINE_GRAPH(title, value)
```

### Draw line graphs that share a single plot

Line graphs with the same id share the same plot.

``` cpp
ArduPlot::LineGraph(String title, double value, unsigned int id)
```

or, if you want a more optimized function, but the `title` and `id` fields need to be string literals:

``` cpp
ARDUPLOT_SHARED_LINE_GRAPH(title, value, id)
```

### Draw a heatmap

The `sizex` and `sizey` parameters tell [ArduPlot](https://github.com/Dave879/ArduPlot) how many squares to draw respectively in the horizontal and vertical direction.

`arr`: the array of data itself

`size`: the size of the array

`min` and `max` define the lowest and highest range that the data will have. It's used for coloring the heatmap.

``` cpp
ArduPlot::Heatmap(String title, unsigned int sizex, unsigned int sizey, double min, double max, T arr, unsigned int size)
```

or, if you want a more optimized function, but the `title`, `sizex`, `sizey`, `min`, `max` fields need to be string literals:

``` cpp
ARDUPLOT_HEATMAP_MIN_MAX(title, sizex, sizey, min, max, arr, size)
```

An override of the function above without the min/max parameters, in this case they can be chosen at runtime when running ArduPlot

``` cpp
ArduPlot::Heatmap(String title, unsigned int sizex, unsigned int sizey, T arr, unsigned int size)
```

or, if you want a more optimized function, but the `title`, `sizex`, `sizey` fields need to be string literals:

``` cpp
ARDUPLOT_HEATMAP(title, sizex, sizey, arr, size)
```
