/************************************************************************************
 *    
 *  OTAppData.cpp
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


#ifdef _WIN32
#include <WinsockWrapper.h>
#include <Shlobj.h>
#endif



#include "OTAppData.h"
#include "simpleini/SimpleIni.h"





class OTAppData
{
private:
	OTAppData();

	OTString WorkingFolderName;

	OTString GetFullUserDataLocationFromSystem(){
		#ifdef _WIN32

		
		TCHAR szPath[MAX_PATH];

		if(SUCCEEDED(SHGetFolderPath(NULL, 
                             CSIDL_APPDATA|CSIDL_FLAG_CREATE, 
                             NULL, 
                             0, 
                             szPath))) ;

		#ifdef UNICODE
		std::string stdpath = utf8util::UTF8FromUTF16(szPath);
		#else
		std::string string(szPath);
		std::string stdpath = szPath;
		#endif

		return stdpath;

		// Old Code... Good, except worked for Windows Vista or greater only.
		// We should use this code when we decide to disscontinue Win XP support.

		//wchar_t* roamingAppData = 0;
		//SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &roamingAppData);

		//std::wstring basicstring(roamingAppData);

		//std::string stdstring = utf8util::UTF8FromUTF16(basicstring);

		//return stdstring;
#else
		return getenv("HOME");
#endif
	}

	OTString ReadRelativeWorkingPathFromOTConfigFile(OTString OTConfigFullPath, OTString OTConfigPathSetting){

		OTString WorkingFolderName;
		CSimpleIniA ini;

		SI_Error rc = ini.LoadFile(OTConfigFullPath.Get());
		if (rc >=0)
		{
			const char * pVal = ini.GetValue("paths", OTConfigPathSetting.Get());
			if (NULL != pVal)
			{
				WorkingFolderName.Set(pVal);
				return WorkingFolderName;
			}         
		}
		return NULL;
	};



public:
	// Constructor:
	// eg. "/home/user/" , ".ot", "client_data"
	OTString OTConfigFullPath;

	OTAppData(OTString WorkingFolderName, OTString OTConfigPathSetting, OTString OTAppDataPath, OTString OTConfigFileName){

		// We have the full location of the OT Configuration... Lets First Try it.
		if (NULL != &OTAppDataPath)
		{
			if (NULL != &OTConfigFileName)
			{

				OTConfigFullPath.Format(OTAppDataPath.Get(),

				WorkingFolderName = ReadRelativeWorkingPathFromOTConfigFile(OTAppDataPath, OTConfigPathSetting);
			}

			WorkingFolderName = ReadRelativeWorkingPathFromOTConfigFile(OTConfigFullPath, OTConfigPathSetting);
		};







	};

	~OTAppData();

	OTFilesystem GetOTFilesystem();
};


OTString OTFilesystem::OTPathSeparator = "/";
OTString OTFilesystem::__OTPathSeparator = "\\";

class OTFilesystem
{
private:
	OTFilesystem();
public:

	// Constructor:
	// eg. "/home/user/" , ".ot", "client_data"
	OTFilesystem(OTString FullUserDataLocation, OTString AppDataFolderName, OTString WorkingFolderName);
	~OTFilesystem();

	OTString MakeDirectory(OTString location, OTString name);  //If succeded, will return location of new directoty.
	OTString MakeDirectoryIfMissing(OTString location, OTString name);  //If succeded or directory already ezists, will return location of directoty.

	OTString LegacyTransformPath(OTString path); // eg. "~/.ot/client_data/wallet" -> "/home/user/.ot/client_data/wallet"
	OTString ToFullPath(OTString path); // eg. "wallet" -> "/home/user/.ot/client_data/wallet"

	OTString GetRelativeOTAppDataPath(); // eg. ".ot" or "OpenTransactions"
	OTString GetFullOTAppDataPath(); // eg. "/home/user/.ot" or "C:/Users/User/AppData/Roaming/OpenTransactions"

	OTString GetRelativeWorkingPath(); // eg. "client_data" or "server_data"
	OTString GetFullWorkingPath(); // eg. "/home/user/.ot/client_data" or "C:/Users/User/AppData/Roaming/OpenTransactions/server_data"

	

};


	
template <class T>
class OTPath : OTSting
{
private:
	OTPath();
public:
	OTString T AsString();

	class Full
	{
	private:
		Full();
	public:
		Full(OTString);
		Full(Relative);
		~Full();
	};

	class Relative
	{
	private:
		Relative();
	public:
		Relative(OTString);
		Relative(Full);
		~Relative();
	};
	~OTPath()
};




