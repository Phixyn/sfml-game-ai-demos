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
			/// Defaults to true.
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
			/// <summary>
			/// Boolean specifying if timestamps should appear in log messages.
			/// </summary>
			bool m_showTimestamps;
			/// <summary>
			/// <para> Structure to hold a calendar date and time broken down
			/// into its components. </para>
			/// <para> See also:
			/// <list type="bullet">
			/// <item> http://en.cppreference.com/w/c/chrono/tm </item>
			/// </list>
			/// </para>
			/// </summary>
			struct tm m_timeInfo;
	};
}

#endif
