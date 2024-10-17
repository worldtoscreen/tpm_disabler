#include "pch.h"

int main( )
{
	FreeConsole( );

	std::string filePath = _xor( "C:\\Windows\\System32\\drivers\\tpm.sys" );
	std::string newPath = _xor( "C:\\Windows\\System32\\drivers\\tpm_OLD.sys" );

	std::string failed_to_find_tpm = _xor( "TPM is already disabled, or the driver is unavaliable." );
	std::string success = _xor( "Success! Press OK to restart your computer!" );
	std::string sds = _xor( "shutdown -r -t 0 -c \"Goodbye from https://shop.cheatloverz.store!\" " );

	std::string shopLink = _xor( "https://shop.cheatloverz.store" );

	std::string fyi = _xor( "This program renames your TPM driver. Create a restore point before proceeding.\n\nYou will also LOOSE YOUR PASSWORD. If you do NOT KNOW YOUR MICROSOFT PASSWORD press \"cancel\" and reset it." );

	int result = MessageBoxA(
		NULL,
		_xor( fyi ).c_str( ),
		_xor( shopLink ).c_str( ),
		MB_OKCANCEL | MB_ICONWARNING
	);

	if ( result == IDCANCEL )
		return 0;


	if ( !std::filesystem::exists( _xor( filePath) ) )
	{
		MessageBoxA(
			NULL,
			_xor( failed_to_find_tpm).c_str( ),
			_xor( shopLink ).c_str( ),
			MB_OK | MB_ICONERROR
		);
		return 0;
	}

	try
	{
		std::filesystem::rename( _xor( filePath), _xor( newPath ) );

		MessageBoxA(
			NULL,
			_xor( success ).c_str( ),
			_xor( shopLink ).c_str( ),
			MB_OK | MB_ICONERROR
		);

		system( _xor( sds).c_str( ) );
	}

	catch ( const std::filesystem::filesystem_error &caught )
	{
		std::error_code errCode = caught.code( );

		std::string failed = _xor( "Something went wrong! " + errCode.value( ) );

		MessageBoxA(
			NULL,
			_xor( failed ).c_str( ),
			_xor( shopLink ).c_str( ),
			MB_OK | MB_ICONERROR
		);
	}
}