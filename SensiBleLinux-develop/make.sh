gcc examples/ibm-watsons/humming-publish.c \
$(pkg-config --cflags --libs glib-2.0) -I/gattlib/include -I/iot-embeddedc/src -I/iot-embeddedc/lib \
-L/gattlib/build/dbus -l:libgattlib.so -L/iot-embeddedc/build/src -l:libiotfdeviceclient.so \
-L/iot-embeddedc/build/lib -l:libmbedtls.a -l:libmbedcrypto.a -l:libmbedx509.a -l:libmqttlib.a -l:libcJSON.a \
-lgcov -o humming-publish
