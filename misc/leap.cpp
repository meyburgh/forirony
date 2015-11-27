// https://github.com/meyburgh/forirony
#include "Leap.h" // the leap sdk header
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace
{
	void LeapVideo()
	{
		Leap::Controller controller;
		controller.setPolicy(Leap::Controller::POLICY_IMAGES);
		
		cv::String const windowName[] = { "0", "1" };
		
		while (controller.isConnected())
		{
			Leap::Frame const frame = controller.frame(0);

			Leap::ImageList const & imageList = frame.images();
			uint8_t const imageCount = imageList.count();

			for (uint8_t imageIndex = 0; imageIndex < imageCount; ++imageIndex)
			{
				Leap::Image const & image = imageList[imageIndex];
				//Leap::Vector v = image.rectify() // you can rectify the video images this way, but it's slow, best to use a shader

				//image.data() points at width * height * bytes per pixel, 8-bit intensity values
				uint32_t const rows = image.height();
				uint32_t const columns = image.width();
				cv::Mat const mat(rows, columns, CV_8UC1);
				uint32_t const imageSize = sizeof(uint8_t) * rows * columns * image.bytesPerPixel();
				memcpy(mat.data, image.data(), imageSize);
				
				cv::imshow(windowName[imageIndex], mat);
				cv::waitKey(16); // 60 fps poor man's frame limiter
			}
		}
	}
}

int main(int const argc, char const * const * const argv)
{
	LeapVideo();

	return 0;
}
