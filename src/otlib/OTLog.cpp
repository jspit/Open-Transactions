/*******************************************************************
*    
*  OTLog.cpp
*  
*/

/************************************************************
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

*                 OPEN TRANSACTIONS
*
*       Financial Cryptography and Digital Cash
*       Library, Protocol, API, Server, and GUI 
*    
*    	 -- Anonymous Numbered Accounts.
*    	 -- Untraceable Digital Cash.
*    	 -- Triple-Signed Receipts.
*    	 -- Cheques, Vouchers, Transfers, Inboxes.
*    	 -- Basket Currencies, Markets, Payment Plans.
*    	 -- Signed, XML, Ricardian-style Contracts.
*    
*  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
*
*  EMAIL:
*  FellowTraveler@rayservers.net
*  
*  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
*
*  KEY FINGERPRINT (PGP Key in license file):
*  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
*
*  OFFICIAL PROJECT WIKI(s):
*  https://github.com/FellowTraveler/Moneychanger
*  https://github.com/FellowTraveler/Open-Transactions/wiki 
*
*  WEBSITE:
*  http://www.OpenTransactions.org/
*    
*  Components and licensing:
*   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
*   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
*   -- OT-API........A client API..........LICENSE:...LAGPLv3
*   -- testwallet....Command-line client...LICENSE:...LAGPLv3
*   -- OT-Server.....Server Application....LICENSE:....AGPLv3
*  Github.com/FellowTraveler/Open-Transactions/wiki/Components
*
*  All of the above OT components were designed and written by
*  Fellow Traveler, with the exception of Moneychanger, which
*  was contracted out to Vicky C (livewire_3001@yahoo.com).
*
*  -----------------------------------------------------
*
*   LICENSE:
*   This program is free software: you can redistribute it
*   and/or modify it under the terms of the GNU Affero
*   General Public License as published by the Free Software
*   Foundation, either version 3 of the License, or (at your
*   option) any later version.
*    
*   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
*   section 7: (This paragraph applies only to the LAGPLv3
*   components listed above.) If you modify this Program, or
*   any covered work, by linking or combining it with other
*   code, such other code is not for that reason alone subject
*   to any of the requirements of the GNU Affero GPL version 3.
*   (==> This means if you are only using the OT-API, then you
*   don't have to open-source your code--only your changes to
*   Open Transactions itself must be open source. Similar to
*   LGPLv3, except it applies to software-as-a-service, not
*   just to distributing binaries.)
*
*   Extra WAIVER for OpenSSL, Lucre, and all other libraries
*   used by Open Transactions: This program is released under
*   the AGPL with the additional exemption that compiling,
*   linking, and/or using OpenSSL is allowed. The same is true
*   for any other open source libraries included in this
*   project: complete waiver from the AGPL is hereby granted to
*   compile, link, and/or use them with Open Transactions,
*   according to their own terms, as long as the rest of the
*   Open Transactions terms remain respected, with regard to
*   the Open Transactions code itself.
*    
*   Lucre License:
*   This code is also "dual-license", meaning that Ben Lau-
*   rie's license must also be included and respected, since
*   the code for Lucre is also included with Open Transactions.
*   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
*   The Laurie requirements are light, but if there is any
*   problem with his license, simply remove the Lucre code.
*   Although there are no other blind token algorithms in Open
*   Transactions (yet. credlib is coming), the other functions
*   will continue to operate.
*   -----------------------------------------------------
*   You should have received a copy of the GNU Affero General
*   Public License along with this program.  If not, see:
*   http://www.gnu.org/licenses/
*
*   If you would like to use this software outside of the free
*   software license, please contact FellowTraveler.
*   (Unfortunately many will run anonymously and untraceably,
*   so who could really stop them?)
*   
*   DISCLAIMER:
*   This program is distributed in the hope that it will be
*   useful, but WITHOUT ANY WARRANTY; without even the implied
*   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*   PURPOSE.  See the GNU Affero General Public License for
*   more details.
-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1.4.11 (Darwin)

iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
6h9BYZFTZrh/OwBXCdAv
=MUfS
-----END PGP SIGNATURE-----
**************************************************************/

// The long-awaited logging class.


#include <cstdarg>
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cerrno>

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

#include <string> // The C++ one 

#ifdef _WIN32
#include <WinsockWrapper.h>
#include <Shlobj.h>
#include <direct.h>
#else
#include <unistd.h>
#endif



#ifdef _WIN32
#define OT_CONFIG_DIR "OpenTransactions"
#else
#define OT_CONFIG_DIR ".ot"
#endif

#define OT_INIT_CONFIG_FILENAME "ot_init.cfg"
#define OT_HOME_DIR "."
#define OT_USER_SCRIPTS_DIR "scripts"
#define OT_SCRIPTS_DIR "scripts"
#define OT_LIB_DIR "opentxs"
#define OT_CONFIG_ISRELATIVE "is_relative"

// ----------------------------------------
// OpenSSL for Windows
//
#ifdef _WIN32

#ifdef _DEBUG
#pragma comment( lib, "libeay32MDd.lib" )
#pragma comment( lib, "ssleay32MDd.lib" )
#else
#pragma comment( lib, "libeay32MD.lib" )
#pragma comment( lib, "ssleay32MD.lib" )
#endif


#endif
// ----------------------------------------

extern "C" 
{

#ifdef _WIN32

#include <sys/timeb.h>

	// For signal handling in Windows.
	//
	LONG  Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo);
	void  LogStackFrames(void *FaultAdress, char *);

#else // else if NOT _WIN32

	// ----------------------------------------
	// These added for the signal handling:
	//
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef __USE_GNU
#define __USE_GNU
#endif

	// This shitty apple section is for struct sigcontext for the signal handling.
#if defined(__APPLE__)
#define _XOPEN_SOURCE 600
	// Fucking Apple!
	struct sigcontext
	{
		int eip;
	};
#endif // defined __APPLE__
	//#define __APPLE_API_OBSOLETE
	//#include <sys/signal.h>
	//#include <sys/ucontext.h>
	//#else
#include <signal.h>
#include <ucontext.h>
	//#endif

#include <wordexp.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <execinfo.h>
	//#endif
	// ----------------------------------------

#endif // not _WIN32

#include <sys/stat.h>
} // extern C
// ---------------------------

// TinyThread++
//
#include "tinythread.h"   // These are in the header already.
//#include "fast_mutex.h"

using namespace tthread;

// ---------------------------------------------------------------------------

//#include "ot_default_paths.h"

// ---------------------------------------------------------------------------

#ifndef _WIN32

void ot_terminate(void);

namespace {
	// invoke set_terminate as part of global constant initialization
	static const bool SET_TERMINATE = std::set_terminate(ot_terminate);
}
#endif


#ifdef ANDROID
#include <android/log.h>
#endif


#include "OTString.h"
#include "OTLog.h"

static dequeOfStrings __logDeque; // Stores the last 1024 logs in memory.




// ---------------------------------------------------------------------------------

// Private; never actually called.
OTLog::OTLog() { }

// Never actually called. Never instantiated.
OTLog::~OTLog() { }


#ifndef _WIN32  // No Windows for now.
#include "stacktrace.h"
#endif

// *********************************************************************************
//
//
//  OTLog Static Vairables
//
//

static OTString __Version = "0.82.i";

#if defined (DSP)					   
static int OTLog::__CurrentLogLevel = 0;	// If you build with DSP=1, it assumes a special location for OpenSSL,
#else								// and it turns off all the output.
static int __CurrentLogLevel = 0;
#endif


// Just a default value, since this is configurable programmatically.
static OTString __OTCronFolder				= "cron";		
static OTString __OTNymFolder				= "nyms";		
static OTString __OTAccountFolder			= "accounts";	
static OTString __OTUserAcctFolder			= "useraccounts";	
static OTString __OTReceiptFolder			= "receipts";		
static OTString __OTNymboxFolder			= "nymbox";		
static OTString __OTInboxFolder				= "inbox";		
static OTString __OTOutboxFolder			= "outbox";	
static OTString __OTPaymentInboxFolder		= "paymentInbox";		
static OTString __OTRecordBoxFolder			= "recordBox";
static OTString __OTCertFolder				= "certs";		
static OTString __OTPubkeyFolder			= "pubkeys";
static OTString __OTContractFolder			= "contracts";
static OTString __OTMintFolder				= "mints";
static OTString __OTSpentFolder				= "spent";
static OTString __OTPurseFolder				= "purse";
static OTString __OTMarketFolder			= "markets";
static OTString __OTScriptFolder			= "scripts";
static OTString __OTSmartContractsFolder	= "smartcontracts";
static OTString __OTPathSeparator			= "/";

static OTString __OTLogfile;		// Optional, logfile (full path.)

// These are only default values. There are configurable in the config file.
static bool	__blocking = false;	// Normally false. This means we will wait FOREVER when trying to send or receive.

// Delay after each message is sent (client side only.)
static int	__latency_send_delay_after = 50;	// It's 50 here after every server request, but also there's a default sleep of 50 in the java GUI after groups of messages.
static int	__latency_send_no_tries = 2; // Number of times will try to send a message.
static int	__latency_receive_no_tries = 2; // Number of times will try to receive a reply.
static int	__latency_send_ms = 5000; // number of ms to wait before retrying send.
static int	__latency_receive_ms = 5000; // number of ms to wait before retrying receive.
static long	__minimum_market_scale = 1;	// Server admin can configure this to any higher power-of-ten.



// *********************************************************************************
//
//
//  OTLog Static Assessors
//
//

const char *	OTLog::Version() { return __Version.Get(); }

// *********************************************************************************

// If it MUST output, set the verbosity to 0. Less important logs are
// at higher and higher levels.
//
// All are sent to stdout, but the 0 are the most important ones.
// By default, only those are actually logged. If you want to see the other messages,
// then set this log level to a higher value sometime when you start execution.
// (Or right here.)

int		OTLog::GetLogLevel() { return __CurrentLogLevel; }
void	OTLog::SetLogLevel(int nLevel) { __CurrentLogLevel = nLevel; }
// ------------------------------------------------------------

const char *	OTLog::CronFolder()				{ return __OTCronFolder.Get(); }
void OTLog::SetCronFolder(const char * szPath)	{ __OTCronFolder.Set(szPath); }

const char *	OTLog::NymFolder()				{ return __OTNymFolder.Get(); }
void OTLog::SetNymFolder(const char * szPath)	{ __OTNymFolder.Set(szPath); }

const char *	OTLog::ReceiptFolder()				{ return __OTReceiptFolder.Get(); }
void OTLog::SetReceiptFolder(const char * szPath)	{ __OTReceiptFolder.Set(szPath); }

const char *	OTLog::NymboxFolder()				{ return __OTNymboxFolder.Get(); }
void OTLog::SetNymboxFolder(const char * szPath)	{ __OTNymboxFolder.Set(szPath); }

const char *	OTLog::AccountFolder()				{ return __OTAccountFolder.Get(); }
void OTLog::SetAccountFolder(const char * szPath){ __OTAccountFolder.Set(szPath); }

const char *	OTLog::UserAcctFolder()				{ return __OTUserAcctFolder.Get(); }
void OTLog::SetUserAcctFolder(const char * szPath){ __OTUserAcctFolder.Set(szPath); }

const char *	OTLog::InboxFolder()				{ return __OTInboxFolder.Get(); }
void OTLog::SetInboxFolder(const char * szPath)	{ __OTInboxFolder.Set(szPath); }

const char *	OTLog::OutboxFolder()				{ return __OTOutboxFolder.Get(); }
void OTLog::SetOutboxFolder(const char * szPath)	{ __OTOutboxFolder.Set(szPath); }

const char *	OTLog::PaymentInboxFolder()		{ return __OTPaymentInboxFolder.Get(); }
void OTLog::SetPaymentInboxFolder(const char * szPath)	{ __OTPaymentInboxFolder.Set(szPath); }

const char *	OTLog::RecordBoxFolder()			{ return __OTRecordBoxFolder.Get(); }
void OTLog::SetRecordBoxFolder(const char * szPath)	{ __OTRecordBoxFolder.Set(szPath); }

const char *	OTLog::CertFolder()				{ return __OTCertFolder.Get(); }
void OTLog::SetCertFolder(const char * szPath)	{ __OTCertFolder.Set(szPath); }

const char *	OTLog::PubkeyFolder()				{ return __OTPubkeyFolder.Get(); }
void OTLog::SetPubkeyFolder(const char * szPath){ __OTPubkeyFolder.Set(szPath); }

const char *	OTLog::ContractFolder()			{ return __OTContractFolder.Get(); }
void OTLog::SetContractFolder(const char * szPath)	{ __OTContractFolder.Set(szPath); }

const char *	OTLog::MintFolder()			{ return __OTMintFolder.Get(); }
void OTLog::SetMintFolder(const char * szPath)	{ __OTMintFolder.Set(szPath); }

const char *	OTLog::SpentFolder()				{ return __OTSpentFolder.Get(); }
void OTLog::SetSpentFolder(const char * szPath)	{ __OTSpentFolder.Set(szPath); }

const char *	OTLog::PurseFolder()				{ return __OTPurseFolder.Get(); }
void OTLog::SetPurseFolder(const char * szPath)	{ __OTPurseFolder.Set(szPath); }

const char *	OTLog::MarketFolder()				{ return __OTMarketFolder.Get(); }
void OTLog::SetMarketFolder(const char * szPath){ __OTMarketFolder.Set(szPath); }

const char *	OTLog::ScriptFolder()				{ return __OTScriptFolder.Get(); }
void OTLog::SetScriptFolder(const char * szPath){ __OTScriptFolder.Set(szPath); }

const char *	OTLog::SmartContractsFolder()		{ return __OTSmartContractsFolder.Get(); }
void OTLog::SetSmartContractsFolder(const char * szPath)	{ __OTSmartContractsFolder.Set(szPath); }

const char *	OTLog::Logfile()				{ return __OTLogfile.Get(); }
void OTLog::SetLogfile(const char * szPath)	{ __OTLogfile.Set(szPath); }

const char *	OTLog::PathSeparator()				{ return __OTPathSeparator.Get(); }
void OTLog::SetPathSeparator(const char * szPath)	{ __OTPathSeparator.Set(szPath); }

// ------------------------------------------------------------

bool	OTLog::IsBlocking() { return __blocking; }
void	OTLog::SetBlocking(bool bBlocking) { __blocking = bBlocking; }

int      OTLog::GetLatencyDelayAfter() { return __latency_send_delay_after; }
void     OTLog::SetLatencyDelayAfter(int nVal) { __latency_send_delay_after = nVal; }

int      OTLog::GetLatencySendNoTries() { return __latency_send_no_tries; }
void     OTLog::SetLatencySendNoTries(int nVal) { __latency_send_no_tries = nVal; }
int      OTLog::GetLatencyReceiveNoTries() { return __latency_receive_no_tries; }
void     OTLog::SetLatencyReceiveNoTries(int nVal) { __latency_receive_no_tries = nVal; }

int      OTLog::GetLatencySendMs() { return __latency_send_ms; }
void     OTLog::SetLatencySendMs(int nVal) { __latency_send_ms = nVal; }
int      OTLog::GetLatencyReceiveMs() { return __latency_receive_ms; }
void     OTLog::SetLatencyReceiveMs(int nVal) { __latency_receive_ms = nVal; }

long	OTLog::GetMinMarketScale() { return __minimum_market_scale; }
void	OTLog::SetMinMarketScale(const long & lMinScale) { __minimum_market_scale = lMinScale; }


// *********************************************************************************
//
//
//  OTLog Functions
//
//

// If there's no logfile, then send it to stderr.
// (So we can still see it on the screen, but it doesn't interfere with any
// command line utilities who might otherwise interpret it as their own input,
// if I was actually writing to stdout.)
//
void OTLog::LogToFile(const char * szOutput)
{
	// Append to logfile
	if ((NULL != szOutput) && (NULL != &__OTLogfile))
	{
		std::ofstream logfile;
		logfile.open (OTLog::Logfile(), std::ios::app);

		if(!logfile.fail())
		{
			logfile << szOutput;
			logfile.close();
		}
	}
	//	else // We now do this either way. 
	{
		std::cerr << szOutput;	
		std::cerr.flush();
	}
};



// *********************************************************************************

const char * OTLog::GetMemlogAtIndex(int nIndex)
{
	unsigned int uIndex = static_cast<unsigned int> (nIndex);

	if ((nIndex < 0) || (uIndex >= __logDeque.size()))
	{
		OTLog::vError("%s: index out of bounds: %d\n", __FUNCTION__, nIndex);
		return NULL;
	}

	OTString * pStr = __logDeque.at(uIndex);

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;
}


// --------------------------------------------------
// We keep 1024 logs in memory, to make them available via the API.

int OTLog::GetMemlogSize() 
{
	return __logDeque.size();
}


const char * OTLog::PeekMemlogFront()
{
	if (__logDeque.size() <= 0)
		return NULL;

	OTString * pStr = __logDeque.front();

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;
}


const char * OTLog::PeekMemlogBack()
{
	if (__logDeque.size() <= 0)
		return NULL;

	OTString * pStr = __logDeque.back();

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;	
}


bool OTLog::PopMemlogFront()
{
	if (__logDeque.size() <= 0)
		return false;

	OTString * pStr = __logDeque.front();

	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}

	__logDeque.pop_front();

	return true;		
}


bool OTLog::PopMemlogBack()
{
	if (__logDeque.size() <= 0)
		return false;

	OTString * pStr = __logDeque.back();

	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}

	__logDeque.pop_back();

	return true;			
}


bool OTLog::PushMemlogFront(const char * szLog)
{
	OT_ASSERT(NULL != szLog);

	OTString * pStr = new OTString(szLog);

	OT_ASSERT(NULL != pStr);

	__logDeque.push_front(pStr);

	if (__logDeque.size() > 1024) // todo: stop hardcoding.
	{
		OTLog::PopMemlogBack(); // We start removing from the back when it reaches this size.
	}

	return true;
}

bool OTLog::PushMemlogBack(const char * szLog)
{
	OT_ASSERT(NULL != szLog);

	OTString * pStr = new OTString(szLog);

	OT_ASSERT(NULL != pStr);

	__logDeque.push_back(pStr);

	return true;	
}

// -------------------------------------------------------

void OTLog::SleepSeconds(long lSeconds)
{
#ifdef _WIN32
	Sleep(1000 * lSeconds);
#else
	sleep(lSeconds);
#endif	
}


void OTLog::SleepMilliseconds(long lMilliseconds)
{
#ifdef _WIN32
	Sleep( lMilliseconds );
#else
	usleep( lMilliseconds * 1000 );
#endif	
}

// -------------------------------------------------------

// This function is for things that should NEVER happen.
// In fact you should never even call it -- use the OT_ASSERT() macro instead.

int OTLog::Assert(const char * szFilename, int nLinenumber, const char * szMessage)
{
	if (NULL != szMessage)
	{
#ifndef ANDROID // if NOT android
		std::cerr << szMessage << "\n";		
		// -----------------------------
		LogToFile(szMessage); LogToFile("\n");
		// -----------------------------

#else // if Android
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", szMessage);
#endif

#ifndef _WIN32
		print_stacktrace();
#endif
	}

	return OTLog::Assert(szFilename, nLinenumber);
}

int OTLog::Assert(const char * szFilename, int nLinenumber)
{
	if ((NULL != szFilename))
	{
#ifndef ANDROID // if NOT android
		std::cerr << "OT_ASSERT in " << szFilename << " at line " << nLinenumber << "\n";

		// -----------------------------
		// Grab this if we can, too...
		//
		OTString strTemp;
		strTemp.Format("OT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		LogToFile(strTemp.Get());
		// -----------------------------

#else // if Android
		OTString strAndroidAssertMsg;
		strAndroidAssertMsg.Format("\nOT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", (const char *)strAndroidAssertMsg.Get());
#endif

#ifndef _WIN32
		print_stacktrace();
#endif

	}

	abort();
	return -1;
}



// -------------------------------------------------------

// For normal output. The higher the verbosity, the less important the message.
// (Verbose level 0 ALWAYS logs.) Currently goes to stdout.

void OTLog::Output(int nVerbosity, const char *szOutput)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	//	if (nVerbosity > OTLog::__CurrentLogLevel || (NULL == szOutput))
	if ((nVerbosity > __CurrentLogLevel) || (NULL == szOutput) || (__CurrentLogLevel == (-1)))		
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szOutput);

	// ---------------------------------------

#ifndef ANDROID // if NOT android

	LogToFile(szOutput);

#else // if IS Android
	/*
	typedef enum android_LogPriority {
	ANDROID_LOG_UNKNOWN = 0,
	ANDROID_LOG_DEFAULT,    // only for SetMinPriority()
	ANDROID_LOG_VERBOSE,
	ANDROID_LOG_DEBUG,
	ANDROID_LOG_INFO,
	ANDROID_LOG_WARN,
	ANDROID_LOG_ERROR,
	ANDROID_LOG_FATAL,
	ANDROID_LOG_SILENT,     // only for SetMinPriority(); must be last
	} android_LogPriority;
	*/
	switch (nVerbosity) {
	case 0:
	case 1:
		__android_log_write(ANDROID_LOG_INFO,"OT Output", szOutput);
		break;
	case 2:
	case 3:
		__android_log_write(ANDROID_LOG_DEBUG,"OT Debug", szOutput);
		break;
	case 4:
	case 5:
		__android_log_write(ANDROID_LOG_VERBOSE,"OT Verbose", szOutput);
		break;
	default:
		__android_log_write(ANDROID_LOG_UNKNOWN,"OT Unknown", szOutput);
		break;
	}
#endif
}

void OTLog::Output(int nVerbosity, OTString & strOutput)
{
	if (strOutput.Exists())
		OTLog::Output(nVerbosity, strOutput.Get());
}

// the vOutput is to avoid name conflicts.
void OTLog::vOutput(int nVerbosity, const char *szOutput, ...)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	if (((0 != __CurrentLogLevel) && (nVerbosity > __CurrentLogLevel)) || (NULL == szOutput))
		return; 

	va_list args;

	// _WIN32
	static char * new_string = NULL;

	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH]; // This only happens once -- static var.

		OT_ASSERT(NULL != new_string);

		memset(new_string, 0, MAX_STRING_LENGTH);
	}

	new_string[0] = '\0';
	// _end _WIN32

	va_start(args, szOutput);

#ifdef _WIN32
	vsprintf_s(new_string, MAX_STRING_LENGTH, szOutput, args);
#else
	vsnprintf(new_string, MAX_STRING_LENGTH, szOutput, args);
#endif

	va_end(args);

	OTLog::Output(nVerbosity, new_string);
}



// -----------------------------------------------------------------

// An error has occurred, that somehow doesn't match the Assert or Output functions.
// So use this one instead.  This ALWAYS logs and currently it all goes to stderr.

void OTLog::Error(const char *szError)
{
	if ((NULL == szError))
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szError);

#ifndef ANDROID // if NOT android

	LogToFile(szError);

#else // if Android
	__android_log_write(ANDROID_LOG_ERROR,"OT Error", szError);
#endif
}

void OTLog::Error(OTString & strError)
{
	if (strError.Exists())
		OTLog::Error(strError.Get());
}

// the vError name is to avoid name conflicts
void OTLog::vError(const char *szError, ...)
{
	if ((NULL == szError))
		return; 

	va_list args;

	// _WIN32
	static char * new_string = NULL;

	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH]; // This only happens once -- static var.

		OT_ASSERT(NULL != new_string);

		memset(new_string, 0, MAX_STRING_LENGTH);
	}

	new_string[0] = '\0';
	// _end _WIN32

	va_start(args, szError);

#ifdef _WIN32
	vsprintf_s(new_string, MAX_STRING_LENGTH, szError, args);
#else
	vsnprintf(new_string, MAX_STRING_LENGTH, szError, args);
#endif

	va_end(args);

	OTLog::Error(new_string);
};



// NOTE: if you have problems compiling on certain platforms, due to the use
// of errno, then just use preprocessor directives to carve those portions out
// of this function, replacing with a message about the unavailability of errno.
//
//static
void  OTLog::Errno(const char * szLocation/*=NULL*/) // stderr
{   
	const int errnum = errno;
	char buf[128]; buf[0] = '\0';

	int nstrerr = 0;
	char * szErrString = NULL;

	//#if((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !defined(_GNU_SOURCE))

#if defined(_GNU_SOURCE) && defined(__linux__)
	szErrString = strerror_r(errnum, buf, 127);
#elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
	nstrerr = strerror_r(errnum, buf, 127); // (strerror_r is threadsafe version of strerror)
#endif

	const char * szFunc = "OTLog::Errno";
	const char * sz_location = (NULL == szLocation) ? "" : szLocation;

	if (NULL == szErrString)
		szErrString = buf;
	// ------------------------
	if (0 == nstrerr)
		OTLog::vError("%s %s: errno %d: %s.\n", 
		szFunc, sz_location,
		errnum, szErrString[0] != '\0' ? szErrString : "");
	else
		OTLog::vError("%s %s: errno: %d. (Unable to retrieve error string for that number.)\n", 
		szFunc, sz_location,
		errnum);
}




// *********************************************************************************
//
//
//  Configuration Helpers
//
//

CSimpleIniA OTLog::iniSimple;


bool OTLog::SetConfigOption_bool(const char * szSection, const char * szKey, bool bVariableName){

	OTLog::CheckSetConfig_bool(szSection,szKey,bVariableName,bVariableName);
	return true;
};

bool OTLog::LogSettingChange_str(const char * szCategory,const char * szOption,const char * szValue){

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(0, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),szValue);
	return true;
};

bool OTLog::LogSettingChange_long(const char * szCategory,const char * szOption,long lValue){

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(0, "Setting %s %s %d \n",strCategory.Get(),strOption.Get(),lValue);
	return true;
};

bool OTLog::LogSettingChange_bool(const char * szCategory,const char * szOption,bool bValue){

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(0, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),bValue ? "true" : "false");
	return true;
};

bool OTLog::StringFill(OTString & out_strString, const char * szString,const int iLength,const char * szAppend) {
	std::string strString(szString);
	if (NULL != szAppend) strString.append(szAppend);
	for(;(strString.length() < iLength);strString.append(" "));
	out_strString.Set(strString.c_str());
	return true;
};


// Returns False no setting is found.  Will not atempt to set value.
bool OTLog::CheckConfig_str(const char * szSection, const char * szKey, OTString & out_strResult){

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	if (NULL == szVar) return false;
	else {
		out_strResult.Set(szVar);
		if (out_strResult.Compare("")) return false;
		else return true;
	};
};

bool OTLog::CheckConfig_bool(const char * szSection, const char * szKey, bool & out_bResult){

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);
	out_bResult = false;

	if (!strVar.Exists()) {
		out_bResult = false;
		return false;
	};
	if (strVar.Compare("true")) out_bResult = true;
	else if (strVar.Compare("false")) out_bResult = false;
	else return false;

	return true;
};

bool OTLog::SetConfig_str(const char * szSection, const char * szKey, const OTString & strResult){
	OT_ASSERT(strResult.Exists());
	if (!strResult.Compare("")) {
		OTLog::LogSettingChange_str(szSection,szKey,strResult.Get());
		OTLog::iniSimple.SetValue(szSection, szKey,strResult.Get(),NULL,true);
		return true;
	}
	else {
		OTLog::LogSettingChange_str(szSection,szKey,"Deleted");
		OTLog::iniSimple.Delete(szSection,szKey,false);
		return false;
	};
};

bool OTLog::SetConfig_bool(const char * szSection, const char * szKey, const bool bValue) {
	OTString strValue(bValue ? "true" : "false");
	OTLog::LogSettingChange_bool(szSection,szKey,bValue);
	OTLog::iniSimple.SetValue(szSection, szKey,strValue.Get(),NULL,true);
	return true;
};

// Returns False if default isn't set and no setting is found.
bool OTLog::CheckSetConfig_str(const char * szSection, const char * szKey, const char * szDefault, OTString & out_strResult){

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar), strDefault(szDefault);

	if (!strVar.Exists()) {
		if (!strDefault.Exists()) return false;  // we have nothing, return false.
		else {
			strVar = strDefault;
			OTLog::LogSettingChange_str(szSection,szKey,strVar.Get());
			OTLog::iniSimple.SetValue(szSection, szKey,strVar.Get(),NULL,true);  // set default value
		};
	};

	out_strResult = strVar;
	return true;
};

bool OTLog::CheckSetConfig_long(const char * szSection, const char * szKey, long lDefault,long & out_lResult){

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);

	if (!strVar.Exists()) {
		OTLog::LogSettingChange_long(szSection,szKey,lDefault);
		OTLog::iniSimple.SetLongValue(szSection, szKey,lDefault,NULL,false,true);  // set default value
	};

	out_lResult = OTLog::iniSimple.GetLongValue(szSection, szKey,NULL);
	return true;
};

bool OTLog::CheckSetConfig_bool(const char * szSection, const char * szKey, bool bDefault,bool & out_bResult){

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar), strDefault(bDefault ? "true" : "false");

	if (!strVar.Exists())
		if (strVar.Compare("true")) out_bResult = true;
		else if (strVar.Compare("false")) out_bResult = false;
		else {
			strVar = strDefault; // set string value
			out_bResult = bDefault;  // set output value
			OTLog::LogSettingChange_str(szSection,szKey,strVar.Get());
			OTLog::iniSimple.SetValue(szSection,szKey,strVar.Get(),NULL,true);  // set default value
		};
		return true;
};


SI_Error OTLog::LoadConfiguration(const OTString & strConfigurationFileExactPath){
	return OTLog::iniSimple.LoadFile(strConfigurationFileExactPath.Get());
};

SI_Error OTLog::SaveConfiguration(const OTString & strConfigurationFileExactPath){
	return OTLog::iniSimple.SaveFile(strConfigurationFileExactPath.Get());
};

bool OTLog::ResetConfiguration(){
	OTLog::iniSimple.Reset();
	return true;
};

bool OTLog::IsConfigurationEmpty(){
	return OTLog::iniSimple.IsEmpty();
};


// *********************************************************************************
//
//
//  Storage Helpers
//
//

// Used for making sure that certain necessary folders actually exist. (Creates them otherwise.)
//
// If you pass in "spent", then this function will make sure that "<path>/spent" actually exists, 
// or create it. WARNING: If what you want to pass is "spent/sub-folder-to-spent" then make SURE
// you call it with "spent" FIRST, so you are sure THAT folder has been created, otherwise the
// folder creation will definitely fail on the sub-folder call (if the primary folder wasn't
// already there, that is.)
//

bool OTLog::ConfirmOrCreateFolder(const OTString & strFolderName) {
	OT_ASSERT_MSG((strFolderName.Exists() && !strFolderName.Compare("")),"OTLog::ConfirmOrCreateFolder: Assert failed: no strFolderName");

	OTString strFolderNameFull, strBasePath;
	OTLog::GetPath_Data(strBasePath);
	OTLog::RelativePathToCanonical(strFolderNameFull,strBasePath,strFolderName);

	return  OTLog::ConfirmOrCreateExactFolder(strFolderNameFull);
};

bool OTLog::ConfirmOrCreateExactFolder(const OTString & strFolderName) {
	OT_ASSERT_MSG((strFolderName.Exists() && !strFolderName.Compare("")),"OTLog::ConfirmOrCreateFolder: Assert failed: no strFolderName");

	// DIRECTORY IS PRESENT?
	struct stat st;

	bool bDirIsPresent = (0 == stat(strFolderName.Get(), &st));

	// ----------------------------------------------------------------------------

	// IF NO, CREATE IT
	if (!bDirIsPresent)
	{
#ifdef _WIN32
		if (_mkdir(strFolderName.Get()) == -1) 
#else
		if (mkdir(strPath.Get(), 0700) == -1) 
#endif
		{
			OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable to create %s.\n",
				strFolderName.Get());
			return false;
		}

		// Now we have created it, so let's check again...
		bDirIsPresent = (0 == stat(strFolderName.Get(), &st));

		if (bDirIsPresent)
			OTLog::vOutput(0, "Created folder: %s\n", strFolderName.Get());
	}

	// ----------------------------------------------------------------------------

	// At this point if the folder still doesn't exist, nothing we can do. We
	// already tried to create the folder, and SUCCEEDED, and then STILL failed 
	// to find it (if this is still false.)
	if (!bDirIsPresent)
	{
		OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable to find newly-created folder: %s\n", 
			strFolderName.Get());
		return false;
	}
	return true;
};


// Returns true or false whether a specific file exists.
// Adds the main path prior to checking.
bool OTLog::ConfirmFile(const OTString & strFileName) {
	OT_ASSERT_MSG((strFileName.Exists() && !strFileName.Compare("")),"OTLog::ConfirmFile: Assert failed: no strFileName");

	OTString strFileNameFull, strBasePath;
	OTLog::GetPath_Data(strBasePath);
	OTLog::RelativePathToCanonical(strFileNameFull,strBasePath,strFileName);

	return OTLog::ConfirmExactFile(strFileNameFull);
};

// Returns true or false whether a specific file exists.
// Adds the main path prior to checking.
bool OTLog::ConfirmExactFile(const OTString & strFileName) {

	long lFileLength = 0;
	return OTLog::ConfirmExactFile(strFileName,lFileLength);
};

bool OTLog::ConfirmExactFile(const OTString & strFileName, long & lFileLength) {
	OT_ASSERT_MSG((strFileName.Exists() && !strFileName.Compare("")),"OTLog::ConfirmExactFile: Assert failed: no strFileName");

	OTLog::vOutput(1,"OTLog::ConfirmExactFile: Looking at: %s...   ",strFileName);

	if (!OTLog::ConfirmExactPath(strFileName)){
		OTLog::vOutput(1,"UNABLE TO FIND PATH\n");
		return false;
	} else {
		OTLog::vOutput(1,"Path Found... Now Checking if File... ");
	};

	int status;
#ifdef _WIN32
	struct _stat st_buf;
	char filename[4086];
	strcpy_s(filename,strFileName.Get());
	status = _stat(filename, &st_buf );
#else
	struct stat st_buf;
	status = stat (szFileName, &st_buf);
#endif
	if( status != 0 ){
		OTLog::vOutput(1,"COULD NOT GET STAT\n");
		return false;
	}
	else if (!S_ISREG(st_buf.st_mode)){	OTLog::vOutput(1,"Is not a File, Bad!\n"); return false; }
	else {
		lFileLength = static_cast<long>(st_buf.st_size);
		OTLog::vOutput(1,"Is a File, Good! With a length of: %d\n",lFileLength);
		return true;
	};
};


// Returns true or false whether a specific file exists.
bool OTLog::ConfirmExactPath(const OTString & strFileName) {
	OT_ASSERT_MSG((strFileName.Exists() && !strFileName.Compare("")),"OTLog::ConfirmExactFile: Assert failed: no strFileName");

	// FILE IS PRESENT?
	struct stat st;

	return (0 == stat(strFileName.Get(), &st));
};

// ---------------------------------------------------------------------------------






// -------------------------------------------------
// OT Paths
//

static OTString __HomePath = "";
static OTString __ConfigPath = "";
static OTString __DataPath = "";
static OTString __PrefixPath = "";
static OTString __LibPath = "";
static OTString __ScriptsPath = "";


bool OTLog::GetPath(const OTString & strPrivateVar, OTString & out_strPath) {

	OT_ASSERT_MSG(strPrivateVar.Exists(),"OTLog::GetPath: strPrivateVar dosn't exist");

	if (strPrivateVar.Compare("")) {
		out_strPath.Set("");
		return false;
	}
	else {
		out_strPath = strPrivateVar;
		return true;
	};
};

bool OTLog::GetPathFromConfig(const char * szKeyName, OTString & out_strVar, bool & out_bIsRelative) {

	OTString strKeyName(szKeyName);
	OT_ASSERT_MSG(strKeyName.Exists(),"OTLog::GetPathFromConfig: strKeyName dosn't exist");
	OT_ASSERT_MSG(!strKeyName.Compare(""),"OTLog::GetPathFromConfig: strKeyName is 0 length)");

	OTString strKeyRelative;
	strKeyRelative.Format("%s%s%s",strKeyName.Get(),"_",OT_CONFIG_ISRELATIVE);

	if (!OTLog::CheckConfig_str("paths",szKeyName,out_strVar)) {
		out_strVar.Set("");
		out_bIsRelative = false;
		return false;
	};

	if (!OTLog::CheckConfig_bool("paths",strKeyRelative.Get(),out_bIsRelative)) {
		out_bIsRelative = false;
		return false;
	};

	return true;
};

bool OTLog::SetPath(OTString & out_strPrivateVar, const OTString & strPathCanonical){

	OT_ASSERT_MSG(strPathCanonical.Exists(),"OTLog::SetPathExact: strPathCanonical dosn't exist");
	OT_ASSERT_MSG(!strPathCanonical.Compare(""),"OTLog::SetPathExact: strPathCanonical is 0 length");

	out_strPrivateVar = strPathCanonical;

	return true;
};


bool OTLog::SetPathToConfig(const OTString & strValue, const char * szKeyName, const bool & bIsRelative) {

	OTString strKeyName(szKeyName), strRelativeKeyName;
	OT_ASSERT_MSG(strKeyName.Exists(),"OTLog::SetPathToConfig: strKeyName dosn't exist");
	OT_ASSERT_MSG(!strKeyName.Compare(""),"OTLog::SetPathToConfig: strKeyName is 0 length)");

	OT_ASSERT_MSG(strValue.Exists(),"OTLog::SetPathToConfig: strValue dosn't exist");
	OT_ASSERT_MSG(!strValue.Compare(""),"OTLog::SetPathToConfig: strValue is 0 length)");

	strRelativeKeyName.Format("%s%s%s",szKeyName,"_",OT_CONFIG_ISRELATIVE);

	if (!OTLog::SetConfig_bool("paths",strRelativeKeyName.Get(),bIsRelative)) return false;
	if (!OTLog::SetConfig_str("paths",szKeyName,strValue)) return false;

	return true;
};

bool OTLog::RelativePathToCanonical(OTString & out_strCanonicalPath, const OTString & strBasePath, const OTString & strRelativePath) {
	OTString  strExactPath;

	OT_ASSERT_MSG(strBasePath.Exists(),"OTLog::RelativePathToCanonical: strBasePath dosn't exist");
	OT_ASSERT_MSG(!strBasePath.Compare(""),"OTLog::RelativePathToCanonical: strBasePath is 0 length)");
	OT_ASSERT_MSG(strRelativePath.Exists(),"OTLog::RelativePathToCanonical: strRelativePath dosn't exist");
	OT_ASSERT_MSG(!strRelativePath.Compare(""),"OTLog::RelativePathToCanonical: strRelativePath is 0 length)");

	strExactPath.Format("%s%s%s", strBasePath.Get(), OTLog::PathSeparator(), strRelativePath.Get());

	return OTLog::PathToRealPath(strExactPath,out_strCanonicalPath);
};

// ------------------------------------------------------------
// OTPath Public High-Level Functions  (stil need to setup Config Before using these).
//
//

// Home Path
bool OTLog::GetPath_Home(OTString & strPath){

	strPath.Set("");
	OTString strHomePathRel;

	if (!OTLog::GetUserDataPath(strHomePathRel)) return false;
	if (!strHomePathRel.Exists()) return false;
	if (strHomePathRel.Compare("")) return false;
	if (OTLog::PathToRealPath(strHomePathRel,strPath)) return true;  // Good.

	strPath.Set("");
	return false;
};


// Config Path
bool OTLog::GetPath_Config(OTString & strPath) { return OTLog::GetPath(__ConfigPath,  strPath); };
bool OTLog::SetPath_Config(const OTString & strPath) { return OTLog::SetPath(__ConfigPath,  strPath); };

bool OTLog::FindPath_Config() {
	// Do we have pre-set config?
	bool bHaveConfig = false, bIsRelative = false;
	OTString strValue, strBasePath, strCanonicalPath;

	bHaveConfig = OTLog::GetPathFromConfig("config",strValue,bIsRelative);
	if (bHaveConfig) // We have a config.
		if (!bIsRelative) // It isn't Relative
			return OTLog::SetPath(__ConfigPath,strValue);

	if (!bHaveConfig) strValue.Set(OT_CONFIG_DIR);

	if (!OTLog::GetPath_Home(strBasePath)) return false; // Get Home Path
	if (!OTLog::RelativePathToCanonical(strCanonicalPath,strBasePath,strValue)) return false;

	if (!OTLog::SetPathToConfig(strValue,"config",true)) return false;
	if (!OTLog::SetPath_Config(strCanonicalPath)) return false; // Set Config Path

	return true;
};


// Data Path
bool OTLog::GetPath_Data(OTString & strPath) { return OTLog::GetPath(__DataPath,  strPath); };
bool OTLog::SetPath_Data(const OTString & strPath) { return OTLog::SetPath(__DataPath,  strPath); };
bool OTLog::FindPath_Data(const OTString & strConfigKeyName) {
	OT_ASSERT_MSG(strConfigKeyName.Exists(),"OTLog::FindPath_Data: strConfigKeyName dosn't exist");
	OT_ASSERT_MSG(!strConfigKeyName.Compare(""),"OTLog::FindPath_Data: strConfigKeyName is 0 length)");

	// Do we have pre-set config?
	bool bHaveConfig = false, bIsRelative = false;
	OTString strValue, strBasePath, strCanonicalPath;

	bHaveConfig = OTLog::GetPathFromConfig(strConfigKeyName.Get(),strValue,bIsRelative);
	if (bHaveConfig) // We have a config.
		if (!bIsRelative) // Exact. Just need to set.
			return OTLog::SetPath(__DataPath,strValue);

	if (!bHaveConfig) strValue = strConfigKeyName;

	if (!OTLog::GetPath_Config(strBasePath)) return false; // Get Config Path
	if (!OTLog::RelativePathToCanonical(strCanonicalPath,strBasePath,strValue)) return false;

	if (!OTLog::SetPathToConfig(strValue,strConfigKeyName.Get(),true)) return false;
	if (!OTLog::SetPath_Data(strCanonicalPath)) return false;  // Set Data Path

	return true;
};


// Prefix Path
bool OTLog::GetPath_Prefix(OTString & strPath) { return OTLog::GetPath(__PrefixPath,  strPath); };
bool OTLog::FindPath_Prefix() {

	OTString strExecutablePath, strExecutableFolderPath , strPrefixPathRelative, strPrefixPath;
	if (!OTLog::GetExecutablePath(strExecutablePath)) return false;  // Get the location of where are running.

	// We only want the drive, and dir parts.  Not the filename or extension:

#ifdef _WIN32
	char path_buffer[_MAX_PATH], drive[_MAX_DRIVE], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
	errno_t err;

	err = _splitpath_s(strExecutablePath.Get(),drive,dir,fname,ext);
	OT_ASSERT_MSG(0 == err,"Failed Splitting Path");

	err = _makepath_s( path_buffer, _MAX_PATH, drive, dir, NULL, NULL );  // Two nulls for fname and ext.
	OT_ASSERT_MSG(0 == err,"Failed Building Path");

	strExecutableFolderPath.Set(path_buffer);
#else
	strExecutableFolderPath.Format("%s%s",dirname(strExecutablePath.Get()),OTLog::PathSeparator());
#endif

	strPrefixPathRelative.Format("%s%s", strExecutableFolderPath.Get(), "..");
	if (!OTLog::PathToRealPath(strPrefixPathRelative,strPrefixPath)) return false;  // Get the location of where are running.
	return OTLog::SetPath(__PrefixPath,strPrefixPath); // Set Prefix Path
};

// Lib Path
bool OTLog::GetPath_Lib(OTString & strPath) { return OTLog::GetPath(__LibPath,  strPath); };
bool OTLog::SetPath_Lib(const OTString & strPath) { return OTLog::SetPath(__LibPath,  strPath); };
bool OTLog::FindPath_Lib(){

	// On Windows... This Should Be the Config Directory.
#ifdef _WIN32

	OTString strConfigPath;
	if (!OTLog::GetPath_Config(strConfigPath)) return false;
	return OTLog::SetPath_Lib(strConfigPath); // Set Lib Path
#else  // UNIX

	// Do we have pre-set config?
	bool bHaveConfig = false, bIsRelative = false;
	OTString strValue, strBasePath, strCanonicalPathLib, strCanonicalPath;

	bHaveConfig = OTLog::GetPathFromConfig("lib",strValue,bIsRelative);
	if (bHaveConfig) // We have a config.
		if (!bIsRelative) // It isn't Relative
			return OTLog::SetPath(__LibPath,strValue);

	if (!bHaveConfig) strValue.Set(OT_LIB_DIR);

	if (!OTLog::GetPath_Prefix(strBasePath)) return false; // Get Home Path
	if (!OTLog::RelativePathToCanonical(strCanonicalPathLib,strBasePath,"lib")) return false;  //..\lib\

	if (!OTLog::RelativePathToCanonical(strCanonicalPath,strCanonicalPathLib,strValue)) return false;  //..\lib\opentxs\

	if (!OTLog::SetPathToConfig(strValue,"config",true)) return false;
	if (!OTLog::SetPath_Config(strCanonicalPath)) return false; // Set Config Path

	return true;
#endif
};

// Scripts Path
bool OTLog::GetPath_Scripts(OTString & strPath)  { return OTLog::GetPath(__ScriptsPath,  strPath); };
bool OTLog::SetPath_Scripts(const OTString & strPath) { return OTLog::SetPath(__ScriptsPath,  strPath); };
bool OTLog::FindPath_Scripts(){
	// Do we have pre-set config?
	bool bHaveConfig = false, bIsRelative = false;
	OTString strValue, strBasePath, strCanonicalPath;

	bHaveConfig = OTLog::GetPathFromConfig("scripts",strValue,bIsRelative);
	if (bHaveConfig) // We have a config.
		if (!bIsRelative) // It isn't Relative
			return OTLog::SetPath(__ScriptsPath,strValue);

	if (!bHaveConfig) strValue.Set(OT_SCRIPTS_DIR);

	if (!OTLog::GetPath_Lib(strBasePath)) return false; // Get Lib Path
	if (!OTLog::RelativePathToCanonical(strCanonicalPath,strBasePath,strValue)) return false;

	if (!OTLog::SetPathToConfig(strValue,"scripts",true)) return false;
	if (!OTLog::SetPath_Scripts(strCanonicalPath)) return false; // Set Scripts Path

	return true;
};


// *********************************************************************************

bool OTLog::PathToRealPath(const OTString & strPath, OTString & strRealPath){

#ifdef _WIN32
#ifdef _UNICODE	

	const char * szPath = strPath.Get();
	size_t newsize = strlen(szPath) + 1;
	wchar_t * wzPath = new wchar_t[newsize];

	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wzPath, newsize, szPath,4096);

	wchar_t szBuf[4096];

	if(GetFullPathName(wzPath,4096,szBuf,NULL)){
		strRealPath.Set(utf8util::UTF8FromUTF16(szBuf));
		return true;
	}
	else {
		strRealPath.Set("");
		return false;
	};

#else
	char_t szBuf[4096];
	char_t const * szPath = strRealPath.Get();

	if(GetFullPathName(szPath,4096,szBuf,NULL)){
		strRealPath.Set(szBuf);
		return true;
	}
	else {
		strRealPath.Set("");
		return false;
	};

#endif
#else

	char actualpath [PATH_MAX+1];
	char *ptr;

	if (NULL != realpath(strPath.Get(), resolvedPath)) strRealPath.Set(resolvedPath);
	else return false;

#endif

};

bool OTLog::GetCurrentWorkingPath(OTString & strCurrentWorkingPath){

#ifdef _WIN32
	// Windows Common
	TCHAR * szPath;
#ifdef _UNICODE
	// Windows Unicode
#define GetCurrentDir _wgetcwd
#else
	// Windows No-Unicode
#define GetCurrentDir _getcwd
#endif
#else
	// Unix
#define GetCurrentDir getcwd
	char * szPath;
#endif

	// All
	bool r = ((szPath = GetCurrentDir(NULL,0)) == 0);
	OT_ASSERT(0 != r);

	OTString result;

#ifdef _WIN32
#ifdef _UNICODE
	// Windows Unicode
	strCurrentWorkingPath.Set(utf8util::UTF8FromUTF16(szPath));
#endif
#else
	// Unix
	strCurrentWorkingPath.Set(szPath);
#endif
	// All
	return true;
};

bool OTLog::GetExecutablePath(OTString & strExecutablePath){

#ifdef TARGET_OS_MAC
#include <mach-o/dyld.h>
#include <limits.h>

	char bufPath[PATH_MAX + 1];
	uint32_t size = sizeof(bufPath);
	int  bufsize = sizeof(bufPath);
	if (_NSGetExecutablePath(bufPath, &bufsize) == 0)
		strExecutablePath.Set(bufPath);
	else return false
#elif defined __linux__

	char bufPath[1024];
	int len = readlink("/proc/self/exe", bufPath, sizeof(bufPath)-1);
	if (len != -1) {
		buff[len] = '\0';
		strExecutablePath.Set(bufPath);
	}
	else return false;

#elif defined _WIN32

	TCHAR bufPath[ _MAX_PATH+1 ] ; 
	GetModuleFileName( NULL , bufPath , sizeof(bufPath)/sizeof(TCHAR) ) ;

#ifdef UNICODE
	strExecutablePath.Set(utf8util::UTF8FromUTF16(bufPath));
#else
	strExecutablePath.Set(bufPath);
#endif
#else
	return false;
#endif
	return true;

};

bool OTLog::GetUserDataPath(OTString & strUserDataPath){

#ifdef _WIN32
	TCHAR szPath[MAX_PATH];

	if(SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath))) {

#ifdef UNICODE
		strUserDataPath.Set(utf8util::UTF8FromUTF16(szPath));
#else
		strHomePath.Set(szPath);
#endif
	}
	else strUserDataPath.Set("");

#else
	strUserDataPath.Set(getenv("HOME"));
#endif
	return true;
};


bool OTLog::SetupPaths(const OTString & strConfigKeyName){

	OTLog::ResetConfiguration();  // Reset Config
	SI_Error rc = SI_FAIL;  // Lets set the SimpleINI result to fail by default.

	// First... lets manualy set the ot_init.cfg file.
	OTString strUserPathTemp, strConfigDirTemp(OT_CONFIG_DIR), strConifgPathTemp, strInitConfigFilename(OT_INIT_CONFIG_FILENAME), strInitConfigPath;
	OT_ASSERT(OTLog::GetUserDataPath(strUserPathTemp));
	OTLog::RelativePathToCanonical(strConifgPathTemp,strUserPathTemp,strConfigDirTemp);
	OTLog::RelativePathToCanonical(strInitConfigPath,strConifgPathTemp,strInitConfigFilename);

	OTLog::ConfirmOrCreateExactFolder(strConifgPathTemp.Get());

	if (OTLog::ConfirmExactFile(strInitConfigPath.Get())) {
		rc = OTLog::LoadConfiguration(strInitConfigPath);

		// if RC is in a good state... we must have a configuration file.
		if (rc >= 0)
			OTLog::vOutput(0,"We have a config file at: %s \n",strInitConfigPath.Get());
		else {
			OTLog::ResetConfiguration();
			OTLog::vOutput(0,"Config File Unloadable at: %s \n",strInitConfigPath.Get());
		}
	}
	else {
		OTLog::ResetConfiguration();
		OTLog::vOutput(0,"No File at: %s \n",strInitConfigPath.Get());
	};

	// Lets Save, Reset, and Load. (this time we throw an error if the init conifg dosn't load).
	OT_ASSERT(0 <= OTLog::SaveConfiguration(strInitConfigPath));
	OT_ASSERT(OTLog::ResetConfiguration());
	OT_ASSERT(0 <= OTLog::LoadConfiguration(strInitConfigPath));

	//  Now that we have our configuration setup, lets start loading up the paths.
	OTString strHomePath, strConfigPath, strDataPath, strPrefixPath, strLibPath, strScriptsPath;

	// Home Path
	OT_ASSERT(OTLog::GetPath_Home(strHomePath));

	// Config Path
	if (!OTLog::FindPath_Config()) return false;
	else OT_ASSERT(OTLog::GetPath_Config(strConfigPath));

	// Data Path
	if (!OTLog::FindPath_Data(strConfigKeyName)) return false;
	else OT_ASSERT(OTLog::GetPath_Data(strDataPath));

	// Prefix Path
	if (!OTLog::FindPath_Prefix()) return false;
	else OT_ASSERT(OTLog::GetPath_Prefix(strPrefixPath));

	// Lib Path (normaly same as config path on windows).
	if (!OTLog::FindPath_Lib()) return false;
	else OT_ASSERT(OTLog::GetPath_Lib(strLibPath));

	// Scripts Path
	if (!OTLog::FindPath_Scripts()) return false;
	else OT_ASSERT(OTLog::GetPath_Scripts(strScriptsPath));

	//  Finshed with the Config, lets save and reset it.
	OT_ASSERT(0 <= OTLog::SaveConfiguration(strInitConfigPath));
	OT_ASSERT(OTLog::ResetConfiguration());


	// Lets make any of the user paths that may be missing...  and throw an error for the missing non-user paths.

	// User Paths:
	// Lets throw an error if Home dosn't exist:
	OT_ASSERT(OTLog::ConfirmExactPath(strHomePath.Get()));

	// Make Config and Data Dir, if missing.
	OTLog::ConfirmOrCreateExactFolder(strConfigPath.Get());
	OTLog::ConfirmOrCreateExactFolder(strDataPath.Get());

	//Throw if any of the system paths are missing:
	OT_ASSERT(OTLog::ConfirmExactPath(strPrefixPath.Get()));
	OT_ASSERT(OTLog::ConfirmExactPath(strLibPath.Get()));
	OT_ASSERT(OTLog::ConfirmExactPath(strScriptsPath.Get()));


	// Example:
	//OTString strCanonicalPath, strBasePath, strRelativePath("ot.ot");
	//OTLog::GetPath_Scripts(strBasePath);
	//OTLog::RelativePathToCanonical(strCanonicalPath,strBasePath,strRelativePath);
	//OTLog::vOutput(0,"Loading Script: %s ... \n",strCanonicalPath.Get());

	//  All done
	return true;
};






// *********************************************************************************

// SIGNALS
//
// To get the most mileage out of this signal handler, 
// compile it with the options:  -g -rdynamic 
//
// *********************************************************************************
//
//
//  Signal Handler
//
//


#ifdef _WIN32   // Windows SIGNALS

// The windows version is from Stefan Wörthmüller, who wrote an excellent article
// at Dr. Dobbs Journal here:
// http://www.drdobbs.com/architecture-and-design/185300443
//

//static
void OTLog::SetupSignalHandler()
{
	static int nCount = 0;

	if (0 == nCount)
	{
		++nCount;
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)Win32FaultHandler);
	}
}

LONG Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo)
{   
	char  *FaultTx = "";

	switch(ExInfo->ExceptionRecord->ExceptionCode)
	{
	case EXCEPTION_ACCESS_VIOLATION          : FaultTx = "ACCESS VIOLATION"         ; break;
	case EXCEPTION_DATATYPE_MISALIGNMENT     : FaultTx = "DATATYPE MISALIGNMENT"    ; break;
	case EXCEPTION_BREAKPOINT                : FaultTx = "BREAKPOINT"               ; break;
	case EXCEPTION_SINGLE_STEP               : FaultTx = "SINGLE STEP"              ; break;
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED     : FaultTx = "ARRAY BOUNDS EXCEEDED"    ; break;
	case EXCEPTION_FLT_DENORMAL_OPERAND      : FaultTx = "FLT DENORMAL OPERAND"     ; break;
	case EXCEPTION_FLT_DIVIDE_BY_ZERO        : FaultTx = "FLT DIVIDE BY ZERO"       ; break;
	case EXCEPTION_FLT_INEXACT_RESULT        : FaultTx = "FLT INEXACT RESULT"       ; break;
	case EXCEPTION_FLT_INVALID_OPERATION     : FaultTx = "FLT INVALID OPERATION"    ; break;
	case EXCEPTION_FLT_OVERFLOW              : FaultTx = "FLT OVERFLOW"             ; break;
	case EXCEPTION_FLT_STACK_CHECK           : FaultTx = "FLT STACK CHECK"          ; break;
	case EXCEPTION_FLT_UNDERFLOW             : FaultTx = "FLT UNDERFLOW"            ; break;
	case EXCEPTION_INT_DIVIDE_BY_ZERO        : FaultTx = "INT DIVIDE BY ZERO"       ; break;
	case EXCEPTION_INT_OVERFLOW              : FaultTx = "INT OVERFLOW"             ; break;
	case EXCEPTION_PRIV_INSTRUCTION          : FaultTx = "PRIV INSTRUCTION"         ; break;
	case EXCEPTION_IN_PAGE_ERROR             : FaultTx = "IN PAGE ERROR"            ; break;
	case EXCEPTION_ILLEGAL_INSTRUCTION       : FaultTx = "ILLEGAL INSTRUCTION"      ; break;
	case EXCEPTION_NONCONTINUABLE_EXCEPTION  : FaultTx = "NONCONTINUABLE EXCEPTION" ; break;
	case EXCEPTION_STACK_OVERFLOW            : FaultTx = "STACK OVERFLOW"           ; break;
	case EXCEPTION_INVALID_DISPOSITION       : FaultTx = "INVALID DISPOSITION"      ; break;
	case EXCEPTION_GUARD_PAGE                : FaultTx = "GUARD PAGE"               ; break;
	default: FaultTx = "(unknown)";           break;
	}
	int    wsFault    = ExInfo->ExceptionRecord->ExceptionCode;
	void * CodeAdress = ExInfo->ExceptionRecord->ExceptionAddress;

	// (using stderr.)
	//  sgLogFile = fopen("Win32Fault.log", "w");

	if(stderr != NULL)
	{
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "*** A Programm Fault occured:\n");
		fprintf(stderr, "*** Error code %08X: %s\n", wsFault, FaultTx);
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "***   Address: %08X\n", (int)CodeAdress);
		fprintf(stderr, "***     Flags: %08X\n", ExInfo->ExceptionRecord->ExceptionFlags);

#if defined (_CONSOLE)
		printf("\n");
		printf("*** A Programm Fault occured:\n");
		printf("*** Error code %08X: %s\n", wsFault, FaultTx);
#endif
		/* This infomation ssems to be wrong
		if(ExInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
		{
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "*** Attempted to %s to address %08LX \n", 
		ExInfo->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
		ExInfo->ExceptionRecord->ExceptionInformation[1]);

		}
		*/ 
#ifdef _WIN64
		//		LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Rbp);
#else
		LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Ebp);
#endif

		//      fclose(sgLogFile);
	}



	/*if(want to continue)
	{
	ExInfo->ContextRecord->Eip++;
	#if defined (_CONSOLE)
	printf("*** Trying to continue\n");
	printf("\n");
	#endif
	return EXCEPTION_CONTINUE_EXECUTION;
	}
	*/ 

	printf("*** Terminating\n");
	printf("\n");
	return EXCEPTION_EXECUTE_HANDLER;
}
/////////////////////////////////////////////////////////////////////////////
// Unwind the stack and save its return addresses to the logfile
/////////////////////////////////////////////////////////////////////////////



void   LogStackFrames(void *FaultAdress, char *eNextBP)

{      
#if defined(_WIN64)

	typedef USHORT (WINAPI *CaptureStackBackTraceType)(__in ULONG, __in ULONG, __out PVOID*, __out_opt PULONG);
	CaptureStackBackTraceType func = (CaptureStackBackTraceType)
		(GetProcAddress(LoadLibrary(L"kernel32.dll"), "RtlCaptureStackBackTrace"));


	if(func == NULL)
		return;

	// Quote from Microsoft Documentation:
	// ## Windows Server 2003 and Windows XP:  
	// ## The sum of the FramesToSkip and FramesToCapture parameters must be less than 63.
	const int kMaxCallers = 62; 

	void* callers[kMaxCallers];
	int count = (func)(0, kMaxCallers, callers, NULL);
	for(int i = 0; i < count; i++)
		fprintf(stderr, "*** %d called from %016I64LX\n", i, callers[i]);

#elif defined (_WIN32) // not _WIN64 ? Must be _WIN32

	char *p = NULL, *pBP = NULL;
	unsigned i = 0, x = 0, BpPassed = 0;
	static int  CurrentlyInTheStackDump = 0;

	if(CurrentlyInTheStackDump)
	{
		fprintf(stderr, "\n***\n*** Recursive Stack Dump skipped\n***\n");
		return;
	}

	fprintf(stderr, "****************************************************\n");
	fprintf(stderr, "*** CallStack:\n");
	fprintf(stderr, "****************************************************\n");

	/* ====================================================================== */
	/*                                                                        */
	/*      BP +x ...    -> == SP (current top of stack)                      */
	/*            ...    -> Local data of current function                    */
	/*      BP +4 0xabcd -> 32 address of calling function                    */
	/*  +<==BP    0xabcd -> Stack address of next stack frame (0, if end)     */
	/*  |   BP -1 ...    -> Aruments of function call                         */
	/*  Y                                                                     */
	/*  |   BP -x ...    -> Local data of calling function                    */
	/*  |                                                                     */
	/*  Y  (BP)+4 0xabcd -> 32 address of calling function                    */
	/*  +==>BP)   0xabcd -> Stack address of next stack frame (0, if end)     */
	/*            ...                                                         */
	/* ====================================================================== */
	CurrentlyInTheStackDump = 1;


	BpPassed = (eNextBP != NULL);

	if(! eNextBP)
	{
		_asm mov     eNextBP, eBp   
	}
	else 
		fprintf(stderr, "\n  Fault Occured At $ADDRESS:%08LX\n", (int)FaultAdress);


	// prevent infinite loops
	for(i = 0; eNextBP && i < 100; i++)
	{      
		pBP = eNextBP;           // keep current BasePointer
		eNextBP = *(char **)pBP; // dereference next BP 

		p = pBP + 8; 

		// Write 20 Bytes of potential arguments
		fprintf(stderr, "         with ");                                                          
		for(x = 0; p < eNextBP && x < 20; p++, x++)
			fprintf(stderr, "%02X ", *(unsigned char *)p);

		fprintf(stderr, "\n\n");                                                          

		if(i == 1 && ! BpPassed) 
			fprintf(stderr, "****************************************************\n"
			"         Fault Occured Here:\n");

		// Write the backjump address
		fprintf(stderr, "*** %2d called from $ADDRESS:%08X\n", i, *(char **)(pBP + 4));

		if(*(char **)(pBP + 4) == NULL)
			break; 
	}


	fprintf(stderr, "************************************************************\n");
	fprintf(stderr, "\n\n");


	CurrentlyInTheStackDump = 0;

	fflush(stderr);
#endif // _WIN64 else (_WIN32) endif
}


// *********************************************************************************

#else  // if _WIN32, else:      UNIX -- SIGNALS

// UNIX

// This is our custom std::terminate handler for SIGABRT
//
void ot_terminate() 
{
	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);

	static bool tried_throw = false;

	try {
		// try once to re-throw currently active exception
		if (!tried_throw) {
			tried_throw = true;
			throw;
		}
	}
	catch (const std::exception &e) {
		std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unhandled exception. type: " << typeid(e).name() << " what(): "
			<< e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unknown/unhandled exception." 
			<< std::endl;
	}

	/*
	void * array[50];
	int size = backtrace(array, 50);    

	std::cerr << "ot_terminate: " << __FUNCTION__ << " backtrace returned " << size << " frames\n\n";

	char ** messages = backtrace_symbols(array, size);

	for (int i = 0; i < size && messages != NULL; ++i) {
	std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
	}
	std::cerr << std::endl;

	free(messages);

	abort();
	*/

	void * array[50];
	int size = backtrace(array, 50);

	char ** messages = backtrace_symbols(array, size);    

	// skip first stack frame (points here)
	for (int i = 1; i < size && messages != NULL; ++i)
	{
		char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

		// find parantheses and +address offset surrounding mangled name
		for (char *p = messages[i]; *p; ++p)
		{
			if (*p == '(') 
			{
				mangled_name = p; 
			}
			else if (*p == '+') 
			{
				offset_begin = p;
			}
			else if (*p == ')')
			{
				offset_end = p;
				break;
			}
		}

		// if the line could be processed, attempt to demangle the symbol
		if (mangled_name && offset_begin && offset_end && 
			mangled_name < offset_begin)
		{
			*mangled_name++ = '\0';
			*offset_begin++ = '\0';
			*offset_end++ = '\0';

			int status;
			char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

			// if demangling is successful, output the demangled function name
			if (status == 0)
			{    
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< real_name << "+" << offset_begin << offset_end 
					<< std::endl;

			}
			// otherwise, output the mangled function name
			else
			{
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< mangled_name << "+" << offset_begin << offset_end 
					<< std::endl;
			}
			free(real_name);
		}
		// otherwise, print the whole line
		else
		{
			std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
		}
	}
	std::cerr << std::endl;

	free(messages);

	abort(); 
}




// CREDIT: the Linux / GNU portion of the signal handler comes from StackOverflow,
// where several answers are combined here.
// http://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes
//

struct sig_ucontext_t {
	//  typedef struct _sig_ucontext {
	unsigned long     uc_flags;
	struct ucontext   *uc_link;
	stack_t           uc_stack;
	struct sigcontext uc_mcontext;
	sigset_t          uc_sigmask;
};

extern "C" {
	// This structure mirrors the one found in /usr/include/asm/ucontext.h 
	//

	void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext);
}

#if defined(OT_NO_DEMANGLING_STACK_TRACE)

// this version doesn't do demangling.
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
	void *             array[50];
	void *             caller_address;
	char **            messages;
	int                size, i;
	sig_ucontext_t *   uc;

	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);

	uc = (sig_ucontext_t *)ucontext;

	// Get the address at the time the signal was raised from the EIP (x86)
	caller_address = (void *) uc->uc_mcontext.eip;   

	fprintf(stderr, "signal %d (%s), address is %p from %p\n", 
		sig_num, strsignal(sig_num), info->si_addr, 
		(void *)caller_address);

	size = backtrace(array, 50);

	// overwrite sigaction with caller's address
	//
	array[1] = caller_address;

	messages = backtrace_symbols(array, size);

	// skip first stack frame (points here)
	//
	for (i = 1; i < size && messages != NULL; ++i)
	{
		fprintf(stderr, "[bt]: (%d) %s\n", i, messages[i]);
	}

	free(messages);

	_exit(0);
}

#else   // #if no demangling, #else...
/*
// This version DOES do demangling.
//
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
sig_ucontext_t * uc = (sig_ucontext_t *)ucontext;

void * caller_address = (void *) uc->uc_mcontext.eip; // x86 specific

std::cerr << "signal " << sig_num 
<< " (" << strsignal(sig_num) << "), address is " 
<< info->si_addr << " from " << caller_address 
<< std::endl << std::endl;

void * array[50];
int size = backtrace(array, 50);

array[1] = caller_address;

char ** messages = backtrace_symbols(array, size);    

// skip first stack frame (points here)
for (int i = 1; i < size && messages != NULL; ++i)
{
char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

// find parantheses and +address offset surrounding mangled name
for (char *p = messages[i]; *p; ++p)
{
if (*p == '(') 
{
mangled_name = p; 
}
else if (*p == '+') 
{
offset_begin = p;
}
else if (*p == ')')
{
offset_end = p;
break;
}
}

// if the line could be processed, attempt to demangle the symbol
if (mangled_name && offset_begin && offset_end && 
mangled_name < offset_begin)
{
*mangled_name++ = '\0';
*offset_begin++ = '\0';
*offset_end++ = '\0';

int status;
char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

// if demangling is successful, output the demangled function name
if (status == 0)
{    
std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
<< real_name << "+" << offset_begin << offset_end 
<< std::endl;

}
// otherwise, output the mangled function name
else
{
std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
<< mangled_name << "+" << offset_begin << offset_end 
<< std::endl;
}
free(real_name);
}
// otherwise, print the whole line
else
{
std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
}
}
std::cerr << std::endl;

free(messages);

_exit(0); 
}
*/

void
	crit_err_hdlr(int sig_num, siginfo_t *info, void *v)
{
	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);


	assert(NULL != v);

	int read = 0;

#ifdef _LP64
	typedef uint64_t ot_ulong;
#else
	typedef uint32_t ot_ulong;
#endif // lp64

	ot_ulong addr=0,
		eip=0,
		esp=0;
	ucontext_t *uc = (ucontext_t *)v;

#if defined(__APPLE__)
	mcontext_t mc;
	mc = uc->uc_mcontext;
	addr = (ot_ulong)info->si_addr;
	read = !(mc->__es.__err&2);
#ifdef _LP64
	eip = mc->__ss.__rip;
	esp = mc->__ss.__rsp;
#else
	eip = mc->__ss.__eip;
	esp = mc->__ss.__esp;
#endif
#elif defined(__linux__)
	mcontext_t *mc;
	struct sigcontext *ctx;
	mc = &uc->uc_mcontext;
	ctx = (struct sigcontext*)mc;
	addr = (ot_ulong)info->si_addr;
	read = !(ctx->err&2);
#ifdef i386
	eip = ctx->eip;
	esp = ctx->esp;
#else
	eip = ctx->rip;
	esp = ctx->rsp;
#endif
#elif defined(__FreeBSD__)
	mcontext_t *mc;
	mc = &uc->uc_mcontext;
#ifdef __i386__
	eip = mc->mc_eip;
	esp = mc->mc_esp;
#elif defined(__amd64__)
	eip = mc->mc_rip;
	esp = mc->mc_rsp;
#endif
	addr = (ot_ulong)info->si_addr;
	if(__FreeBSD__ < 7){
		/*
		* FreeBSD /usr/src/sys/i386/i386/trap.c kludgily reuses
		* frame->tf_err as somewhere to put the faulting address
		* (cr2) when calling into the generic signal dispatcher.
		* Unfortunately, that means that the bit in tf_err that says
		* whether this is a read or write fault is irretrievably gone.
		* So we have to figure it out.  Let's assume that if the page
		* is already mapped in core, it is a write fault.  If not, it is a
		* read fault.  
		*
		* This is apparently fixed in FreeBSD 7, but I don't have any
		* FreeBSD 7 machines on which to verify this.
		*/
		char vec;
		int r;

		vec = 0;
		r = mincore((void*)addr, 1, &vec);
		//iprint("FreeBSD fault [%d]: addr=%p[%p] mincore=%d vec=%#x errno=%d\n", signo, addr, (uchar*)addr-uzero, r, vec, errno);
		if(r < 0 || vec == 0)
			mc->mc_err = 0; /* read fault */
		else
			mc->mc_err = 2; /* write fault */
	}
	read = !(mc->mc_err&2);
#else
#       error   "Unknown OS in sigsegv"
#endif


	void * caller_address = (void *) eip; 

	std::cerr << "signal " << sig_num 
		<< " (" << strsignal(sig_num) << "), address is " 
		<< info->si_addr << " from " << caller_address 
		<< std::endl << std::endl;

	void * array[50];
	int size = backtrace(array, 50);

	array[1] = caller_address;

	char ** messages = backtrace_symbols(array, size);    

	// skip first stack frame (points here)
	for (int i = 1; i < size && messages != NULL; ++i)
	{
		char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

		// find parantheses and +address offset surrounding mangled name
		for (char *p = messages[i]; *p; ++p)
		{
			if (*p == '(') 
			{
				mangled_name = p; 
			}
			else if (*p == '+') 
			{
				offset_begin = p;
			}
			else if (*p == ')')
			{
				offset_end = p;
				break;
			}
		}

		// if the line could be processed, attempt to demangle the symbol
		if (mangled_name && offset_begin && offset_end && 
			mangled_name < offset_begin)
		{
			*mangled_name++ = '\0';
			*offset_begin++ = '\0';
			*offset_end++ = '\0';

			int status;
			char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

			// if demangling is successful, output the demangled function name
			if (status == 0)
			{    
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< real_name << "+" << offset_begin << offset_end 
					<< std::endl;

			}
			// otherwise, output the mangled function name
			else
			{
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< mangled_name << "+" << offset_begin << offset_end 
					<< std::endl;
			}
			free(real_name);
		}
		// otherwise, print the whole line
		else
		{
			std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
		}
	}
	std::cerr << std::endl;

	free(messages);

	_exit(0); 
}


#endif // defined(OT_NO_DEMANGLING_STACK_TRACE)

// --------------------------------------
#ifndef OT_HANDLE_SIGNAL
#define OT_HANDLE_SIGNAL(OT_SIGNAL_TYPE) \
{ \
	\
struct sigaction new_action, old_action; \
	new_action.sa_sigaction = crit_err_hdlr; \
	sigemptyset (&new_action.sa_mask); \
	new_action.sa_flags = SA_RESTART | SA_SIGINFO;  \
	\
	sigaction(OT_SIGNAL_TYPE, NULL, &old_action); \
	\
	if (old_action.sa_handler != SIG_IGN) \
{ \
	if (sigaction(OT_SIGNAL_TYPE, &new_action, NULL) != 0) \
{ \
	OTLog::vError("OTLog::SetupSignalHandler: Failed setting signal handler for error %d (%s)\n", \
	OT_SIGNAL_TYPE, strsignal(OT_SIGNAL_TYPE)); \
	abort(); \
} \
} \
}
#endif
// --------------------------------------

//static
void OTLog::SetupSignalHandler()
{
	static int nCount = 0;

	if (0 == nCount)
	{
		++nCount;
		// --------------------------------------
		OT_HANDLE_SIGNAL(SIGINT)  // Ctrl-C. (So we can shutdown gracefully, I suppose, on Ctrl-C.)
			OT_HANDLE_SIGNAL(SIGSEGV) // Segmentation fault.
			//      OT_HANDLE_SIGNAL(SIGABRT) // Abort.
			OT_HANDLE_SIGNAL(SIGBUS)  // Bus error
			//  OT_HANDLE_SIGNAL(SIGHUP)  // I believe this is for sending a "restart" signal to your process, that sort of thing.
			OT_HANDLE_SIGNAL(SIGTERM) // Used by kill pid (NOT kill -9 pid). Used for "killing softly."
			OT_HANDLE_SIGNAL(SIGILL)  // Illegal instruction.
			OT_HANDLE_SIGNAL(SIGTTIN) // SIGTTIN may be sent to a background process that attempts to read from its controlling terminal.
			OT_HANDLE_SIGNAL(SIGTTOU) // SIGTTOU may be sent to a background process that attempts to write to its controlling terminal.
			//  OT_HANDLE_SIGNAL(SIGPIPE) // Unix supports the principle of piping. When a pipe is broken, the process writing to it is sent the SIGPIPE.
			//  OT_HANDLE_SIGNAL(SIGKILL) // kill -9. "The receiving process cannot perform any clean-up upon receiving this signal."
			OT_HANDLE_SIGNAL(SIGFPE)  // Floating point exception.
			OT_HANDLE_SIGNAL(SIGXFSZ) // SIGXFSZ is the signal sent to a process when it grows a file larger than the maximum allowed size.
			//  OT_HANDLE_SIGNAL(SIGQUIT) // SIGQUIT is the signal sent to a process by its controlling terminal when the user requests that the process perform a core dump.
			OT_HANDLE_SIGNAL(SIGSYS)  // sent when a process supplies an incorrect argument to a system call.
			//  OT_HANDLE_SIGNAL(SIGTRAP) // used by debuggers
			// --------------------------------------
	}
}

#endif  // #if windows, #else (unix) #endif. (SIGNAL handling.)




