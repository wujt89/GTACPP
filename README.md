# GTA C++

Arcade-style mouse shooter built with C++ and Qt. Protect the hero while shooting hostile balloons. Balloons bounce elastically off each other, the hero, and the walls. They also react to the mouse cursor: aiming directly at a balloon causes it to randomly change direction, so you need to lead your shots. A tutorial overlay can be toggled on or off.

## Gameplay
- Clear waves of balloons. Each level spawns 4 balloons; eliminate all to advance.
- The hero loses one life when hit by a red balloon.
- Manage limited time and ammunition.

## Balloon Types
- Red: Standard enemy; moves slowly.
- Blue: Smaller and stationary, harder to spot; destroying a blue balloon spawns a red one.
- Yellow: Fast; destroying a yellow balloon spawns a blue one.

## Game Over Conditions
- Time runs out
- Ammunition runs out
- Hero lives reach zero

## Scoring
Your score is the highest level reached.

## Controls
- Mouse: Aim
- Click: Shoot

## Build and Run
This is a Qt Widgets project using `qmake` (project file: `gra/gra.pro`).

### Prerequisites
- Qt 5.13+ (Qt Widgets)
- C++11-compatible toolchain

### Option A — Qt Creator
1. Open `gra/gra.pro` in Qt Creator.
2. Configure a kit (Qt version and compiler).
3. Build and run from within the IDE.

### Option B — Command Line (qmake)
```bash
qmake gra/gra.pro
make            # or nmake/jom on Windows
./gra           # path and name may vary by OS/configuration
```

## Project Structure
- `gra/`: C++ source code and Qt project file.
- `build-gra-.../`: Example build output and bundled assets (images, sounds, fonts) from a local build.

## Assets
Images, sounds, and fonts needed by the game are included in the repository under the build output folders. If you organize assets differently in your local setup, update the resource loading paths accordingly.
