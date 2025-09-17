### Tipe Data Dasar

Ada tiga kategori utama untuk tipe data dasar:

#### 1. Tipe Data Integer (Bilangan Bulat) 🔢
Digunakan untuk menyimpan angka-angka tanpa desimal.
- **`char`**: Menyimpan karakter, seperti `'A'` atau `'7'`. Secara teknis, `char` menyimpan nilai integer kecil (biasanya -128 hingga 127) yang mewakili karakter dalam set karakter seperti **ASCII**.
- **`int`**: Tipe data integer standar. Ukuran memorinya bervariasi (biasanya 4 byte).
- **`short`**: Mirip dengan `int` tetapi ukurannya lebih kecil (biasanya 2 byte).
- **`long`**: Menjamin ukuran yang sama atau lebih besar dari `int`.
- **`long long`**: Menjamin ukuran yang sama atau lebih besar dari `long` (biasanya 8 byte).

Kamu bisa menambahkan `unsigned` di depan tipe data integer (misalnya, `unsigned int`) untuk hanya menyimpan nilai non-negatif, yang menggandakan jangkauan positifnya.

---

#### 2. Tipe Data Floating-Point (Bilangan Pecahan) 🔬
Digunakan untuk menyimpan angka-angka dengan desimal.
- **`float`**: Tipe data floating-point dengan presisi tunggal.
- **`double`**: Tipe data floating-point dengan presisi ganda. Biasanya lebih disukai karena lebih akurat.
- **`long double`**: Tipe data dengan presisi lebih tinggi dari `double`.

---

#### 3. Tipe Data Boolean (Kebenaran) ✔️
Secara tradisional, C menggunakan integer untuk merepresentasikan nilai kebenaran:
- **`0` (nol)** untuk `false`.
- **Nilai non-nol** untuk `true`.

Sejak standar C99, kamu bisa menggunakan tipe data **`bool`** dengan menyertakan `<stdbool.h>` untuk menggunakan nilai `true` dan `false`.

---

### Tipe Data Turunan

Tipe data ini dibangun di atas tipe data dasar untuk membentuk struktur yang lebih kompleks.

- **`Array`**: Kumpulan dari beberapa variabel dengan tipe data yang sama yang disimpan dalam satu blok memori.
    `int angka[10];` // array integer dengan 10 elemen.

- **`Pointer`**: Variabel yang menyimpan alamat memori dari variabel lain.
    `int *ptr;` // pointer ke integer.

- **`Struct`**: Mengelompokkan variabel-variabel dengan tipe data yang berbeda ke dalam satu unit.
    `struct Person { char nama[50]; int usia; };`

- **`Union`**: Mirip dengan `struct` tetapi semua anggotanya berbagi lokasi memori yang sama.

- **`Enum (Enumeration)`**: Memberikan nama-nama yang mudah dibaca untuk konstanta integer.
    `enum Hari {SENIN, SELASA, RABU};`

- **`Typedef`**: Memberikan nama alias pada tipe data yang sudah ada, membuat kode lebih mudah dibaca.
    `typedef long int large_int;`
