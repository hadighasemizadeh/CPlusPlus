#ifndef BASEENGINE_H
#define BASEENGINE_H

class BaseEngine {
public:
	bool Run(void);

protected:
	bool GetInput(char *c);
	void TimerUpdate(void);

private:
	double frameCounter;
	double startTime;
	double lastTime ;
};
#endif // !BASEENGINE_H

