/*
 * HTTPFlooder.h
 *
 *  Created on: Dec 7, 2012
 *      Author: ivan
 */

#ifndef HTTPFLOODER_H_
#define HTTPFLOODER_H_

#include "Flooder.cpp"
#include <errno.h>


#include <time.h>
#include <fcntl.h>
namespace loic {

class HTTPFlooder: public loic::Flooder {
private:
		enum ReqState { readyState,connectingState,requestingState,downloadingState,completedState,failedState};
		int downloaded;
		int requested;
		int failed;
		std::string subsite;
		int timeout;
		HTTPFlooder::ReqState state;
		time_t lastAction;
		void checkTimeOut();
public:
		HTTPFlooder(std::string ip, std::string port, std::string subSite, bool resp, int delay, int timeout)
		{
			this->ip = ip;
			this->port = port;
			this->subsite = subSite;
			this->resp = resp;
			this->delay = delay;
			this->timeout = timeout;
		};
				//destructor
		virtual ~HTTPFlooder(){};

		inline int Downloaded(){return downloaded;}
		inline int Requested(){return requested;}
		inline int Failed(){return failed;}
		inline std::string Subsite(){return subsite;}
		inline int Timeout(){return timeout;}
		inline HTTPFlooder::ReqState State(){return state;}


		inline void State(HTTPFlooder::ReqState newState){state = newState;}
		inline void Downloaded(int down){downloaded = down;}
		inline void Requested(int req){requested = req;}
		inline void Failed(int fail){failed = fail;}
		inline void Subsite(std::string site){subsite= site;}
		inline void Timeout(int time){timeout= time;}

		void Start();
		void Stop();
		void work();
};

} /* namespace loic */
#endif /* HTTPFLOODER_H_ */
