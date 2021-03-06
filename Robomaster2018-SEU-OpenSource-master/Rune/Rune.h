/**************************************************************

MIT License

Copyright (c) 2018 SEU-SuperNova-CVRA

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Authors:    Shi Shu, <213162637@seu.edu.cn>
            BinYan Hu
            Su ChenHao
            Cui RenJie
            Sun BoWen
**************************************************************/
#pragma once

#include"../General/singleton.hpp"
#include"../General/General.h"
#include"../General/opencv_extended.h"
#include<opencv2/opencv.hpp>
#include<array>

//#define SHOW_PRETREAT			    /*to show the process of pretreat*/
//#define SHOW_FIND_LED			    /*to show the process of finding led*/
//#define DEBUG_FULL                        /*to show the process of detecting rune*/
//#define DEBUG_NUM                         /*to show the result of caculating numbers*/


#define DEBUG_GET_EVERYTHING                /*to get mumbers of classes*/
//#define CASUAL_SET_NUMBER                 /*to set led numbers and rune numbers while debugging*/

namespace rm
{
/*
 * this class contains all possibly modified parameters which may be used at the playing field
*/
	class RuneParam
	{
	public:
		RuneParam(const int _hsv_h_min = 0,
			const int _hsv_h_max = 34,
			const int _hsv_s_min = 43,
			const int _hsv_s_max = 255,
			const int _hsv_v_min = 150,
			const int _hsv_v_max = 255,
			const int _contour_min_area = 130,
			const float _contour_boundingrect_min_aspect_ratio = 0.25,
			const int _contour_boundingrect_max_aspect_ratio = 4,
			const int _contour_boundingrect_min_area = 200,
			const int _contour_boundingrect_max_area = 3000,
			const float _y_direction_dx_max_width_rate = 0.5,
			const float _y_direction_dy_max_height_rate = 2.5,
			const float _x_direction_dx_min_height_rate = 1.5,
			const float _x_direction_dx_max_height_rate = 3.5,
			const float _x_direction_dy_max_height_rate = 1.0,
			const float _centers_max_sin_theta = 0.30) :
			hsv_h_min(_hsv_h_min),
			hsv_h_max(_hsv_h_max),
			hsv_s_min(_hsv_s_min),
			hsv_s_max(_hsv_s_max),
			hsv_v_min(_hsv_v_min),
			hsv_v_max(_hsv_v_max),
			contour_min_area(_contour_min_area),
			contour_boundingrect_min_aspect_ratio(_contour_boundingrect_min_aspect_ratio),
			contour_boundingrect_max_aspect_ratio(_contour_boundingrect_max_aspect_ratio),
			contour_boundingrect_min_area(_contour_boundingrect_min_area),
			contour_boundingrect_max_area(_contour_boundingrect_max_area),
			y_direction_dx_max_width_rate(_y_direction_dx_max_width_rate),
			y_direction_dy_max_height_rate(_y_direction_dy_max_height_rate),
			x_direction_dx_min_height_rate(_x_direction_dx_min_height_rate),
			x_direction_dx_max_height_rate(_x_direction_dx_max_height_rate),
			x_direction_dy_max_height_rate(_x_direction_dy_max_height_rate),
			centers_max_sin_theta(_centers_max_sin_theta)
		{

		}

		const RuneParam operator=(const RuneParam & runeParam)
		{
			this->hsv_h_min = runeParam.hsv_h_min;
			this->hsv_h_max = runeParam.hsv_h_max;
			this->hsv_s_min = runeParam.hsv_s_min;
			this->hsv_s_max = runeParam.hsv_s_max;
			this->hsv_v_min = runeParam.hsv_v_min;
			this->hsv_v_max = runeParam.hsv_v_max;

			this->contour_min_area = runeParam.contour_min_area;
			this->contour_boundingrect_min_aspect_ratio = runeParam.contour_boundingrect_min_aspect_ratio;
			this->contour_boundingrect_max_aspect_ratio = runeParam.contour_boundingrect_max_aspect_ratio;
			this->contour_boundingrect_min_area = runeParam.contour_boundingrect_min_area;
			this->contour_boundingrect_max_area = runeParam.contour_boundingrect_max_area;

			this->y_direction_dx_max_width_rate = runeParam.y_direction_dx_max_width_rate;
			this->y_direction_dy_max_height_rate = runeParam.y_direction_dy_max_height_rate;
			this->x_direction_dx_min_height_rate = runeParam.x_direction_dx_min_height_rate;
			this->x_direction_dx_max_height_rate = runeParam.x_direction_dx_max_height_rate;
			this->x_direction_dy_max_height_rate = runeParam.x_direction_dy_max_height_rate;
			this->centers_max_sin_theta = runeParam.centers_max_sin_theta;
			return *this;
		}
	

		int hsv_h_min = 0;					/*????????????h??????????????????????????????*/
		int hsv_h_max = 34;					/*????????????h??????????????????????????????*/
		int hsv_s_min = 43;					/*????????????s??????????????????????????????*/
		int hsv_s_max = 255;					/*????????????s??????????????????????????????*/
		int hsv_v_min = 150;					/*????????????v??????????????????????????????*/
		int hsv_v_max = 255;					/*????????????v??????????????????????????????*/

		int contour_min_area = 130;				/*???????????????????????????*/
		int contour_boundingrect_min_aspect_ratio = 0.25;	/*????????????????????????????????????*/
		int contour_boundingrect_max_aspect_ratio = 4;		/*????????????????????????????????????*/
		int contour_boundingrect_min_area = 200;		/*?????????????????????????????????*/
		int contour_boundingrect_max_area = 3000;		/*?????????????????????????????????*/

		float y_direction_dx_max_width_rate = 0.5;		/*y???????????????????????????????????????????????????dx???????????????????????????????????????*/
		float y_direction_dy_max_height_rate = 2.5;		/*y???????????????????????????????????????????????????dy???????????????????????????????????????*/
		float x_direction_dx_min_height_rate = 1.5;		/*x???????????????????????????????????????????????????dx???????????????????????????????????????*/
		float x_direction_dx_max_height_rate = 3.5;		/*x???????????????????????????????????????????????????dx???????????????????????????????????????*/
		float x_direction_dy_max_height_rate = 1.0;		/*x???????????????????????????????????????????????????dy???????????????????????????????????????*/
		float centers_max_sin_theta = 0.30;			/*?????????????????????????????????????????????????????????*/

	};
	
    class RuneDetector
	{
	public:
        //RuneDetector() {};
        //~RuneDetector() {};
	enum RuneFlag
	{
		RUNE_NO = 0,				//????????????
		RUNE_PART = 1,				//?????????????????????????????????????????????
		RUNE_FULL = 2,				//??????????????????
		SHOOT_NO = 3,				//??????????????????
            	SHOOT_WAIT = 4,				//???????????????????????????????????????????????????,
		SHOOT_YES = 5,				//????????????
	};

	/*
	*	@brief ????????????????????????
	*/
        void init();

        /*
        *	@brief ????????????
        */
        void setMode(int runeMode, const RuneParam& runeParam);

	/*
	*	@brief ????????????
	*/
	cv::Mat loadImg(cv::Mat mat);

	/*
	*	@brief ???????????????
	*/
        int caculate();

	/*
	*	@brief ????????????????????????????????????
	*/
	cv::Point2f chooseTarget();

        /*
        *	@brief reset parameters
        */
        void resetPara();

	bool isShoot(bool shootSituation)
	{
		isFly_ = shootSituation;
		if (isFly_ == true)
		{
			shootFlag_ = SHOOT_YES;
			return true;
		}
		return false;
	}

		/*
		*	@brief ??????flag
		*/
        int getFlag() const;

#ifdef DEBUG_GET_EVERYTHING
		/*
		*	@brief ???????????????ROI??????
		*/
		const cv::Rect getRuneRoi() const;

		/*
		*	@brief ?????????????????????????????????
		*/
		const std::array<cv::Point2f, 9> getCenters() const;

		/*
		*	@brief ??????????????????9?????????
		*/
		const std::array<int, 9> getRuneNumbers() const;
		/*
		*	@brief ??????LED???5?????????
		*/
		const std::vector<int> getLedNumbers() const;



#endif // DEBUG_GET_EVERYTHING

	private:
        /*
        *	this blob contains the contours' characters found after findContours()
        */
		struct Blob
		{
			Blob() = default;
			Blob(const cv::Point2f& pcenter, const float pwidth,
				 const float pheight, const float parea)
			{
				center = pcenter;
				width = pwidth;
				height = pheight;
				area = parea;

			}
			cv::Point2f center;						/*??????????????????????????????*/
			float width;							/*???????????????????????????*/
			float height;							/*???????????????????????????*/
			float area;							/*????????????????????????????????????????????????????????????????????????*/
			cv::Point coor = {0, 0};					/*????????????????????????*/
		};

        int runeMode_ = 0;								/*?????????????????????*/
		RuneParam params_;							/*????????????*/

		//TODO: double flags
		int runeFlag_;								/*?????????????????????????????????*/
		int shootFlag_;								/*????????????????????????*/

		cv::Mat srcImg_;							/*??????*/
		cv::Mat workImg_;							/*???????????????????????????*/
		cv::Mat perspMat_;
		cv::Mat grayImg_;
		cv::Mat debugImg_;
		const std::string debugImgName = "debug info";

		std::vector<std::vector<cv::Point>> contours_;				/*findContours??????????????????*/
		std::vector<cv::Vec4i> hierachy_;					/*findContours????????????????????????*/

		std::vector<Blob> blobs_;						/*????????????????????????????????????????????????*/
		std::vector<cv::Rect2f> filteredRects_;					/*????????????????????????????????????*/
		//std::vector<cv::Rect2f> final_Rects_;					/*???????????????????????????????????????????????????*/
		std::vector<Blob> finalBlobs_;						/*?????????????????????????????????????????????*/
		
		std::array<cv::Point2f, 9> runeCenters_;				/*?????????9????????????*/
		std::array<int, 9> runeNumbers_;					/*?????????9?????????*/
		std::array<int, 9> oldruneNumbers_;					/*?????????9?????????*/
		std::array<std::pair<cv::Point2f, int>, 9> numbersNcenter_;		/*?????????9?????????????????????*/
		cv::Rect rune_roi_;							/*?????????ROI??????*/

		cv::Rect ledRoi_;							/* ?????????????????????(??????srcImg) */		
		cv::Mat ledImg_;							/* ??????????????? ???????????????????????????????????????*/	
		
		cv::Mat ledProcessingImg_;						/*?????????????????????????????????????????????????????????*/
		std::vector<cv::Rect> ledRects_;					/* LED???????????? */
		std::vector<int> runeLedNumbers_;					/*led???5?????????*/
		std::vector<int> oldruneLedNumbers_;					/*led?????????5?????????*/

		std::list<int> history_;						/*????????????5???LED?????????*/
		int led_idx_ = 0;							/*????????????????????????????????????????????????(??????0~4)*/
		std::array<int, 10> vote;						/*??????????????????*/
		cv::Point2f targetCoor_;						/*?????????????????????????????????????????????*/
		bool isFly_ = false;							/*???????????????????????????????????????true*/

		int debug_count_ = 1;
															
		/*
		*	@brief ?????????????????????
		*/
		int isGreatRune(int runeMode);


		/*
		*	@brief ???HSV????????????????????????????????????
		*	@param1 h??????????????????
		*	@param2 h??????????????????
		*	@param3 s??????????????????
		*	@param4 s??????????????????
		*	@param5 v??????????????????
		*	@param6 v??????????????????
		*	@information
		*		yellow channle of HSV
		*		H???[26,34] S???[43,255] V???[46,255]
		*/
		void chooseColor(int hsv_h_min, int hsv_h_max,
			int hsv_s_min, int hsv_s_max,
			int hsv_v_min, int hsv_v_max);

		/*
		*	@brief ???????????????????????????????????????????????????????????????????????????????????????????????????????????????
		*/
		void preScreen();

		/*
		*	@brief ?????????????????????????????????????????????Blob???????????????
		*		??????????????????Blob????????????????????????????????????????????????
		*		?????????????????????????????????????????????????????????
		*/
		void findRune();

		/*
		*	@brief ????????????????????????
		*/
        	const std::vector<int> findLedNumbers();

		/*
		*	@brief 	?????????????????????
		*			1.?????????????????????
		*			2.????????????????????????6??????????????????
		*			3.???????????????????????????????????????????????????
		*			
		*	??????????????????????????????????????????????????????????????????6??????????????????????????????????????????????????????
		*/
		int findLEDThreshold(const cv::Mat & gray);

		/*
		*	@brief ???????????????????????????????????????????????????????????????
		*/
		int trans2RealLedNum(const cv::Mat& dframe_count);

		/*
		*	@brief ??????ledImg_??????????????????????????????
		*/
        	void getLedImg();

		
		/*
		*	@brief ????????????
		*/
		void  detect();

		/*
		*	@brief ?????????????????????
		*/
		void recognize();

		/*???????????????????????????history_??????1-9???????????????-1????????????*/
		bool setRecord(int record);

		/*????????????????????????*/
		int chooseNumber();


	};

}
