#include "core/log/log.h"
#include "core/error/error.h"
#include "core/memory/memory.h"
#include "core/command_line.h"

int main(int argc, const char* argv[])
{
	haydn::memory_globals::init();
	haydn::log_internals::init();

	haydn::CommandLine l(argc, argv);

#define VERSION "3.8"

	if(l.has_option("log", 'l'))
	{
		HY_INFO("You just called with option --log -l: {}", l.get_parameter(0, "log", 'l'));
	}

	if(l.has_option("version", 'v'))
	{
		HY_INTERNAL_INFO("Version {}", VERSION);
	}

	if(l.has_option("abort", 'e'))
	{
		HY_FATAL("We are sorry");
	}


	haydn::memory_globals::shutdown();
	return 0;
}
