#include <ros/ros.h>
#include <librealsense2/rs.hpp>
#include <string>
#include <unistd.h>


/* Main */
int main(int argc, char **argv)
{
    rs2::context ctx;

    for( auto&& dev : ctx.query_devices() ){
        // Send a reset to all found devices
        dev.hardware_reset();
        sleep( 1 );// Waiting for reconnection
    }
}
