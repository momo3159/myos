#include <Uefi.h>
#include <Library/UefiLib.h>

// day01であった構造体の定義がなくなっている
// EDK2のおかげ
EFI_STATUS EFIAPI UefiMain(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *system_table) {
  Print(L"Hello, Boot Loader");
  while(1);
  return EFI_SUCCESS;
}