<h1>Gazebo Plugin trajectory_guided</h1> <img src="docs/imgs/ros_logo.png" align="right" width="101" height="27" /> 

Author: Roberto Zegers R.

## Instructions

Build the plugin

```
mkdir build
cd build
cmake ../
make
```

Make sure Gazebo can load the plugins later

```
cd ..
export GAZEBO_PLUGIN_PATH=`pwd`:$GAZEBO_PLUGIN_PATH
```

Make sure Gazebo can load the tram model later

```
cd models
export GAZEBO_MODEL_PATH=`pwd`:$GAZEBO_MODEL_PATH
```


Run using Gazebo itself with:

`$ gazebo trajectory_guided.world`

---

This package contains source code obtained of the [Gazebo Animated Box Tutorial](http://gazebosim.org/tutorials?cat=install&tut=animated_box&ver=6.0-7.0), which is licenced under the Apache License, Version 2.0 (http://www.apache.org/licenses/LICENSE-2.0).
