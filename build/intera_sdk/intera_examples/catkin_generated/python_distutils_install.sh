#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/tony/final_project/src/intera_sdk/intera_examples"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/tony/final_project/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/tony/final_project/install/lib/python3/dist-packages:/home/tony/final_project/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/tony/final_project/build" \
    "/usr/bin/python3" \
    "/home/tony/final_project/src/intera_sdk/intera_examples/setup.py" \
    egg_info --egg-base /home/tony/final_project/build/intera_sdk/intera_examples \
    build --build-base "/home/tony/final_project/build/intera_sdk/intera_examples" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/tony/final_project/install" --install-scripts="/home/tony/final_project/install/bin"
