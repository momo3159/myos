#include <stdint.h>

typedef uintptr_t Elf64_Addr;
typedef uint64_t  Elf64_Off;
typedef uint16_t  Elf64_Half;
typedef uint32_t  Elf64_Word;
typedef int32_t   Elf64_Sword;
typedef uint64_t  Elf64_Xword;
typedef int64_t   Elf64_Sxword;

#define EI_NIDENT 16

#define PT_NULL    0
#define PT_LOAD    1
#define PT_DYNAMIC 2
#define PT_INTERP  3
#define PT_NOTE    4
#define PT_SHLIB   5
#define PT_PHDR    6
#define PT_TLS     7

/**
 * ファイルヘッダ  （ファイル全体の情報 ex) 各ヘッダの開始位置）
 * プログラムヘッダ（ローダ向けの情報．ex) 仮想アドレス，必要なメモリサイズ）
 * セクション       (.text, .data, .bssなど)
 * セクションヘッダ (リンカ向けの情報．ex) セクションのファイル内における位置・サイズ)
 */

/**
 * ファイルヘッダ
 * https://docs.oracle.com/cd/E26924_01/html/E25909/chapter6-43405.html
 */
typedef struct {
  unsigned char e_ident[EI_NIDENT]; // ファイルの内容を復号するためのデータ
  Elf64_Half    e_type;             // ファイルの種類（実行可能，再配置可能etc）
  Elf64_Half    e_machine;          // アーキテクチャの種類
  Elf64_Word    e_version;          // ファイルのバージョン
  Elf64_Addr    e_entry;            // 仮想アドレス（エントリーポイントの？）
  Elf64_Off     e_phoff;            // プログラムヘッダのファイルオフセット
  Elf64_Off     e_shoff;            // セクションヘッダのファイルオフセット
  Elf64_Word    e_flags;            // プロセッサ固有のフラグ
  Elf64_Half    e_ensize;           // ELFヘッダのサイズ（バイト）
  Elf64_Half    e_phentsize;        // プログラムヘッダテーブルの1つのエントリのサイズ
  Elf64_Half    e_phnum;            // プログラムヘッダテーブルのエントリ数
  Elf64_Half    e_shentsize;        // セクションヘッダテーブルのサイズ
  Elf64_Half    e_shnum;            // セクションヘッダテーブルのエントリー数
  Elf64_Half    e_shstrndx;         // セクションヘッダテーブルのうち，文字列テーブル（シンボル名をほじしている）がセクションヘッダテーブルの何番目かを表す（）
} Elf64_Ehdr;

/**
 * プログラムヘッダ（の各エントリ）
 * https://docs.oracle.com/cd/E19620-01/805-5821/6j5ga47br/index.html#chapter6-83432
 */
typedef struct {
  Elf64_Word  p_type;    // LOADなどのセグメント種別
  Elf64_Word  p_flags;
  Elf64_Off   p_offset;  // オフセット
  Elf64_Addr  p_vaddr;   // 仮想アドレス
  Elf64_Addr  p_paddr;   // 物理アドレス
  Elf64_Xword p_filesz;  // セグメントのファイルイメージのバイト数
  Elf64_Xword p_memsz;   // セグメントのメモリイメージのバイト数
  Elf64_Xword p_align;   // メモリのアライメントの数
} Elf64_Phdr;