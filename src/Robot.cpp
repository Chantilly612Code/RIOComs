#include "WPILib.h"
#include <I2C.h>

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw = LiveWindow::GetInstance();
	I2C* wire;
	uint8_t* i2c_buffer = new uint8_t[6];

	void RobotInit()
	{
		wire = new I2C(I2C::Port::kMXP, 84);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
	}

	void TeleopInit()
	{
		wire->Read(0x01, 6, i2c_buffer);
		std::printf("%c", (char)i2c_buffer[0]);
		std::printf("%u", i2c_buffer[1]);
		std::printf("%u", i2c_buffer[2]);
		std::printf("%u", i2c_buffer[3]);
		std::printf("%c", (char)i2c_buffer[4]);
		std::printf("\n");
	}

	void TeleopPeriodic()
	{

	}

	void TestPeriodic()
	{
		lw->Run();
	}

	void DisabledInit()
	{
		wire->Read(0x00, 1, i2c_buffer);
	}
	void DisabledPeriodic() {}
};

START_ROBOT_CLASS(Robot)
