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
			/// <summary>
			/// <para> Arithmetic type capable of representing times. </para>
			/// <para> time() returns the current time of the system as time
			/// since epoch. The argument for this function can be a pointer to a
			/// std::time_t object to store the time, or a null pointer. </para>
			/// <para> See also:
			/// <list type="bullet">
			/// <item> http://en.cppreference.com/w/cpp/chrono/c/time_t </item>
			/// <item> http://en.cppreference.com/w/cpp/chrono/c/time </item>
			/// </list>
			/// </para>
			/// </summary>
			std::time_t m_timeT = std::time(nullptr);
			/// <summary>
			/// <para> localtime() converts a given time since epoch into calendar
			/// time, expressed in local time, in the struct tm format. The result
			/// is stored in a struct tm. </para>
			/// <para> localtime_s() is Microsoft's thread-safe version of this
			/// function. Its first argument is a pointer to the time structure to
			/// store the result in. The second argument is a pointer to the time
			/// since epoch time_t to be used. </para>
			/// <para> See also:
			/// <list type="bullet">
			/// <item>
			/// https://msdn.microsoft.com/en-us/library/a442x3ye(v=vs.140).aspx
			/// </item>
			/// </list>
			/// </para>
			/// <seealso cref="m_timeInfo" />
			/// <seealso cref="m_timeT" />
			/// </summary>
			// TODO: Note localtime_s() can be called in the constructor and
			// its return value does not need to be stored here.
			errno_t m_localtime = localtime_s(&m_timeInfo, &m_timeT);
	};
}

#endif
