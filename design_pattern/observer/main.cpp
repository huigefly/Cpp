#include <stdio.h>
#include <stdlib.h>
#include "boss.h"
#include "clerk.h"
#include "timerWarn.h"

int main()
{
	CTimerWarn tw(10);
	CBoss boss;
	tw.addNotifer(&boss);
	
	CClerk clerk;
	tw.addNotifer(&clerk);
	tw.removeNotifer(&boss);
	
	tw.run();

	return 0;
}