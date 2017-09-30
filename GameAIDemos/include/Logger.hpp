#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iomanip>
#include <time.h>

namespace GameAIDemos
{
	/// <summary>
	/// Provides a very simple logging utility for the game.
	/// </summary>
	class Logger
	{
	public:
		/// <summary>
		/// Default constructor. Sets the m_showTimestamps member variable.
		/// </summary>
		///
		/// <param name="showTimestamps">
		/// A boolean specifying if timestamps are shown in log messages.
		/// </param>
		Logger(bool showTimestamps = true);

		/// <summary>
		/// Writes a log message to STDOUT.
		/// </summary>
		///
		/// <param name="level">
		/// Level of importance of the log message (e.g. info).
		/// </param>
		/// <param name="message"> The message to be logged. </param>
		void log(std::string level, std::string message);
	private:
		bool m_showTimestamps;
		/// <summary>
		/// TODO
		/// <summary>
		std::time_t m_time_t = std::time(nullptr);
		/// <summary>
		/// TODO
		/// <summary>
		struct tm m_timeInfo;
		/// <summary>
		/// TODO
		/// <summary>
		errno_t m_localtime_result = localtime_s(&m_timeInfo, &m_time_t);
	};
}

#endif
