// Copyright 2018-19 Eric Fedosejevs
//

#include "Sirelphy/source/precomp.h"
#include "Utilogeny/source/exceptions.h"
//#include "Sirelphy/source/core/globals.h"
//
//std::recursive_mutex* cException::consoleOutMutex = 0;
//
//cException::cException(const std::string & tmpDesc, const char *tmpFile, int tmpLine, std::thread::id tmpID)
//	: description(tmpDesc), file(tmpFile), line(tmpLine), threadID(tmpID) {
//}
//
//// Recursively describes nested exceptions
//void print_exception(const std::exception & e, unsigned int level)
//{
//	std::unique_ptr<std::lock_guard<std::recursive_mutex>> lockGuardPtr;
//	if (cException::consoleOutMutex) {
//		lockGuardPtr.reset(new std::lock_guard<std::recursive_mutex>(*(cException::consoleOutMutex)));
//	}
//
//	// Head level
//	if (!level) {
//		// If it is at the head level, print exception trace
//		std::cerr << "Exception caught in thread " << std::this_thread::get_id() << ". Trace:\n";
//		// Get a console output lock (necessary for multi-threaded cases)
//	}
//
//	// Indent according to exception level
//	std::cerr << "\t" << std::string(level, ' ');
//
//	// If it's an RNA-see exception, provide extra information
//	const cException * internalE = dynamic_cast<const cException *>(&e);
//	if (internalE) {
//		std::cerr << "RNA-see @ " << internalE->getFile() << ":" << internalE->getLine();
//		std::cerr << " (thread " << internalE->getThreadID() << ") - \"";
//		std::cerr << internalE->getDescription() << "\"\n";
//	}
//	else {
//		std::cerr << "STL - \"";
//		std::cerr << e.what() << "\"\n";
//	}
//
//	// See if it's a nested exception
//	try {
//		std::rethrow_if_nested(e);
//	}
//	catch (const std::exception& e) {
//		print_exception(e, level + 1);
//	}
//	// If it was a nested exception but you can't tell what type the inner exception is
//	catch (...) {
//		// Indent according to exception level
//		std::cerr << std::string(level + 1, ' ');
//		std::cerr << "ERROR - unknown type\n";
//	}
//}