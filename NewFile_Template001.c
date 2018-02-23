	if (joy1Btn(5) == 1)
  	{
 	 motor[LeftF] = 100;
 	 motor[LeftR] = 100;
 	 }
 	 //Left Side Strike Buttons Left Weels -100% power Backwords When Pressed
  else if (joy1Btn(7) == 1)
  	{
	  motor[LeftF] = -100;
	  motor[LeftR] = -100;
		}

// Right Side motors 100% power when pressed 100% right side forward
  if (joy1Btn(6) == 1)
  	{
 	 motor[RightF] = 100;
 	 motor[RightR] = 100;
 	 }
	// Right side motors -100% power when pressed -100% Right side Backwards
  else if (joy1Btn(8) == 1)
  	{
	  motor[RightF] = -100;
	  motor[RightR] = -100;
		}
