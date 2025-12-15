
Ringkasan Belajar Golang
1. func main (Si Mandor)
• Aturan Keras: Tidak boleh ada argumen `()` dan tidak boleh ada return value.

• Peran: Sebagai Entry Point & Orchestrator (wiring, setup, panggil fungsi lain). Bukan tempat logika berat.

• Komunikasi dengan OS:

  • Lapor status: Pakai `os.Exit(1)`.

  • Ambil input luar: Pakai `os.Args` atau `os.Getenv`.

2. go build vs go run
• go build (Cetak Foto):

  • Compile jadi file binary (`.exe`) permanen.

  • Code berubah? Harus build ulang.

  • Bisa Cross Compile (misal: build di Windows buat jalan di STB Linux ARM).

• go run (Bercermin):

  • Compile -> Simpan di Temp -> Jalanin -> Hapus.

  • Cocok buat development (selalu baca code terbaru).

3. Variabel `:=` & Scope
• `:=` (Short Declaration): Cara malas bikin variabel (tipe data otomatis). Hanya bisa di dalam fungsi.

• Scope (Umur Variabel):

  • Dibatasi oleh kurung kurawal `{ }` terdekat.

  • Variabel mati/hilang saat ketemu tutup kurung `}`.

  • Hati-hati Shadowing (variabel dalam `{}` menimpa variabel luar dengan nama sama).

4. Printf & `\n`
• `\n` (Newline): Cuma instruksi visual buat terminal ("pindah baris"), bukan penanda akhir data di memori.

• Printf: Kursor tidak pindah baris otomatis (seperti mesin ketik).

• Memory: String di Go = Pointer + Length. Tidak pakai Null Terminator (`\0`) seperti di C.
