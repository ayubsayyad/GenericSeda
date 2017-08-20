#pragma once

#include <thread>

class NoThreadedStategy {};
class SingleThreadedStategy {};

template<typename EType, typename T, typename Strategy>
struct Executor {
	Executor(EType* ev) : e(ev) {}

	void operator()(T& message) {
		e->execute(message);
	}
	EType* e;
};



template <typename EType, typename T>
struct Executor<EType, T, SingleThreadedStategy> {
	Executor(EType* ev) : e(ev) {}

	void operator()(T& message) {
		e->execute(message);
	}
	EType* e;
};
