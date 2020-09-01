// Copyright 2018-19 Eric Fedosejevs
//

#pragma once
#include "Sirelphy/source/precomp.h"
//
//class cException : public std::exception {
//public:
//	cException(const std::string &, const char *file, int line, std::thread::id);
//	const std::string getDescription() const { return description; };
//	const std::string getFile() const { return std::string(file); };
//	const std::string getLine() const { return std::to_string(line); };
//	const std::thread::id getThreadID() const { return threadID; };
//	static void setConsoleOutMutex(std::recursive_mutex* tmpMtx) { consoleOutMutex = tmpMtx; };
//private:
//	friend void print_exception(const std::exception&, unsigned int);
//	const std::string description;
//	const char *file;
//	const int line;
//	const std::thread::id threadID;
//	static std::recursive_mutex* consoleOutMutex;
//};
//
//#define throw_line(arg) throw cException(arg, __FILE__, __LINE__, std::this_thread::get_id());
//#define throw_line_overridden throw_line("Virtual member should have been overridden")
//#define throw_line_not_implemented throw_line("Not yet implemented")
//#define throw_line_deprecated throw_line("Deprecated code")
//#define rethrow_line(arg) std::throw_with_nested(cException(arg, __FILE__, __LINE__, std::this_thread::get_id()));
//
//void print_exception(const std::exception &, unsigned int level = 0);
//
//#define TRY try{
//#define CODE_FAILED_VOCAL_RETHROW(arg) } catch (const std::exception & e) { std::lock_guard<std::recursive_mutex> lock(globals::consoleOutMutex); std::cerr << "Exception caught by " << __FILE__ << ":" << __LINE__ << "\n"; print_exception(e); std::cerr << "Rethrowing.\n\n"; rethrow_line(arg); } catch (...) { rethrow_line(arg);}
//#define CODE_FAILED_SILENT_RETHROW(arg) } catch (...) { rethrow_line(arg);}
//
//#define CODE_FAILED_SILENT_RETHROW(arg) } catch (...) { rethrow_line(arg);}
//
//#define CODE_FAILED_VOCAL_CATCH(arg) } catch (...) { try { try { rethrow_line(arg);} catch (const std::exception & e) { std::lock_guard<std::recursive_mutex> lock(globals::consoleOutMutex); std::cerr << "Exception caught by " << __FILE__ << ":" << __LINE__ << "\n"; print_exception(e); std::cerr << "\n"; }} catch (...) {/* extra catch to make no_except */}}
//
//class cExceptionRemoveBadRuns {
//public:
//	std::vector<std::string> badRunNames;
//};