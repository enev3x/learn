📝 Catatan Penting: File Descriptor
1. Apa itu File Descriptor?
File Descriptor (FD) adalah sebuah integer (bilangan bulat) non-negatif yang digunakan oleh sistem operasi (terutama pada sistem berbasis Unix seperti Linux) sebagai "pegangan" atau "tiket" untuk mengidentifikasi file yang sedang dibuka oleh sebuah program.

- Sistem operasi memperlakukan banyak hal sebagai "file", termasuk:

- File di hard drive (.txt, .jpg, dll.)

- Perangkat I/O (keyboard, printer, layar konsol)

- Koneksi jaringan (soket)

- Pipa untuk komunikasi antar-program

2. Sintaks dan Cara Kerja write()
Fungsi write() yang kamu lihat adalah contoh penggunaan FD. Sintaksnya adalah:

> ssize_t write(int fd, const void *buf, size_t count);

'fd': Argumen ini adalah file descriptor. Angka 1 berarti Standard Output (stdout), yaitu layar atau terminal.

'buf': Ini adalah pointer ke data yang akan ditulis. Dalam kasusmu, itu adalah string "Hello, World!".

'count': Ini adalah jumlah byte yang akan ditulis. Angka 13 berarti 13 karakter dari string "Hello, World!".

Fungsi ini memberitahu sistem operasi: "Tulis count byte data dari buf ke sumber daya yang diidentifikasi oleh fd."

3. Kenapa tidak perlu menulis FD secara eksplisit?
Kamu tidak selalu perlu menulis FD karena ada dua tingkat fungsi I/O:

- Fungsi Tingkat Rendah (Low-Level): Ini adalah system calls yang berinteraksi langsung dengan kernel. Mereka membutuhkan FD secara eksplisit untuk memberi tahu sistem operasi sumber daya mana yang akan diakses. Contohnya: open(), read(), write(), close().

- Fungsi Tingkat Tinggi (High-Level): Ini adalah fungsi yang lebih abstrak dan mudah digunakan. Mereka mengelola FD secara otomatis di balik layar. Contohnya: printf(), scanf(), fopen(), fprintf().

Ketika kamu menggunakan printf(), fungsi itu secara internal memanggil write() dengan FD 1 (stdout) tanpa kamu sadari. Jadi, meskipun kamu tidak melihatnya, FD tetap digunakan.

4. Kesimpulan
Pada dasarnya, file descriptor adalah konsep kunci untuk operasi I/O tingkat rendah. Fungsi-fungsi tingkat tinggi menyembunyikan kerumitan ini untuk memudahkan programmer, tetapi pada akhirnya, mereka semua mengandalkan FD untuk berkomunikasi dengan sistem operasi.

Memahami FD akan memberimu pemahaman yang lebih dalam tentang bagaimana sebuah program berinteraksi dengan dunia luar.
