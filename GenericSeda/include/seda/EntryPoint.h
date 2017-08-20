#pragma once

#include "ProcessingStrategy.h"


template <typename MType, typename Handler, typename Strategy = NoThreadedStategy>
class EntryPoint {
	public:
		EntryPoint(Handler* h): handler(h), executor(this){}

		void process(MType& message) {
			executor(message);
		}

		void execute(MType& message) {
			handler->execute(message);
		}

	private:
		Handler* handler;
		Executor<EntryPoint, MType, Strategy> executor;
};