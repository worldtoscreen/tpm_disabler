# tpm_disabler
TPM disabler.
Create a restore point.
Make sure you know your microsoft account password! You will loose your password after it's done.

This tool works by forcfully renaming your TPM driver to tpm_OLD.sys. Only use this as a last resort for devices that don't have the option to disable TPM.
Compile in x64 release with std::latest (c++ 23) and make sure the uac is requireAdministrator.
