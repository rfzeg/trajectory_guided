<h1>Gazebo Plugin trajectory_guided <img src="docs/imgs/ros_logo.png" align="right" width="101" height="27" /> </h1> 

Author: Roberto Zegers R.

## Instructions

Build the plugin

```
mkdir build
cd build
cmake ../
make
```

Make sure Gazebo can load the plugin:

```
export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH
```

Make sure Gazebo can load the tramway model:

```
cd ..
cd models
export GAZEBO_MODEL_PATH=`pwd`:$GAZEBO_MODEL_PATH
```


Run using Gazebo itself with:

`$ gazebo trajectory_guided.world`

---

This package contains source code obtained of the [Gazebo Animated Box Tutorial](http://gazebosim.org/tutorials?cat=install&tut=animated_box&ver=6.0-7.0), which is licenced under the Apache License, Version 2.0 (http://www.apache.org/licenses/LICENSE-2.0).

## References

- https://community.gazebosim.org/t/limits-of-the-simulation/54
- https://answers.ros.org/question/315752/how-to-simulate-track-guided-robots-railway-vehicle/

## Troubleshooting

- Gazebo is crashing as it is starting up.  
  Usually, it is enough to run it again (probably several times).

- Error [parser.cc] Unable to find uri[model://tram], and unable to find uri[model://grass_plane].  
  Make sure to export the environment variable that set the models paths in each new terminal you open.

- Tramway model does not move.  
  To display the current GAZEBO_PLUGIN_PATH use the command `$ echo $GAZEBO_PLUGIN_PATH`. The path should point directly to the folder where the .so file is located (in this case the build folder).
