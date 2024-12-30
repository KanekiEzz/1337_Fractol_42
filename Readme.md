<h1 align="center">1337🇲🇦_Fractol_42 🖥🇬🇧 Kaneki</h1>
<p align="center">
  <a href="https://github.com/KanekiEzz/1337_Fractol_42">
    <img src="https://raw.githubusercontent.com/KanekiEzz/kaneki_badges/refs/heads/main/fract-olm.png" alt="42 Badge">
  </a>
</p>


---

## 📜 About Project

> One of the first graphical projects at 42 School, fract-ol generates beautiful fractals from the complex numbers of \
> an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at \
> smaller scales. This project uses the school's graphical library, MiniLibX.


## 📑 Fractals List

The program supports these fractal sets:

| Name              | Formula                                                                                            |
|:-----------------:|:--------------------------------------------------------------------------------------------------:|
| Mandelbrot        | $z_{n+1} = z_n^2 + c, z_0 = 0$                                                                     |
| Julia             | $z_{n+1} = z_n^2 + c, z_0 = c$                                                                     |
| Burning Ship      | $z_{n+1} = abs(z_n^2) + c, z_0 = 0$                                                                |
| Tricorn           | $z_{n+1} = \frac{}{z_n}^2 + c, z_0 = 0$                                                            |
| Mandelbox         | It's more complex, see [this article](https://sites.google.com/site/mandelbox/what-is-a-mandelbox) |
| Celtic Mandelbar  | $z_{n+1} = \frac{}{z_n}^2 + c, z_0 = c$                                                            |

## 🎮 Controls

The program supports the following controls:

| Key           | Description                             |
|:-------------:|:---------------------------------------:|
| ESC           | Close the program window                |
| Keys [1-6]    | Move to another fractal                 |
| Keys [Q-Y]    | Change the color of fractal             |
| Keys [A-H]    | Change the color of fractal             |
| Mouse Scroll  | Zoom in and out of the fractal          |
| ⬆️ ⬇️ ⬅️ ➡️     | Change the viewpoint                    |
| Key L         | Lock Julia's fractal                    |
| Zero          | Reset the fractal to its initial state  |

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path/to/fractol && make
```

**2. How to run the program**

Run the executable too see the help message:
```shell
./fractol
```

Or run with some supported fractal:
```shell
./fractol mandelbrot
```

# 🌄 Screenshots

## Mandelbrot set
![Fractal mono-colored Mandelbrot](README_files/screenshots/mandelbrot1.png)
![Fractal red blue and green striped Mandelbrot](README_files/screenshots/mandelbrot2.png)
![Fractal sun crest purple Mandelbrot](README_files/screenshots/mandelbrot3.png)

## Julia set
![Fractal purple green and yellow Julia](README_files/screenshots/julia1.png)
![Fractal red swirl Julia](README_files/screenshots/julia2.png)
![Fractal blue snowflake Julia](README_files/screenshots/julia3.png)

## Burning Ship set
![Fract-ol golden Burning Ship](README_files/screenshots/burning_ship.png)

## Tricorn set
![Fract-ol purple Tricorn](README_files/screenshots/tricorn.png)

## Mandelbox set
![Fract-ol brown tribal Mandelbox](README_files/screenshots/mandelbox.png)