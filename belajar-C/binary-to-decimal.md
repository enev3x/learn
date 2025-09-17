# Rangkuman: Memahami Bit, Byte, dan Sistem Bilangan Biner

---

Berikut adalah rangkuman dari materi yang sudah kita bahas mengenai dasar-dasar komputasi, mulai dari bit hingga cara konversi bilangan biner.

## 1. Bit dan Byte

* **Bit** adalah unit terkecil dari data dalam komputasi. Satu bit hanya bisa memiliki dua nilai, yaitu **0** atau **1**. Bit sering digunakan untuk mengukur kecepatan, contohnya **Mbps** (megabit per detik).
* **Byte** adalah kumpulan dari **8 bit**. Satu byte dapat merepresentasikan 256 nilai berbeda (dari 0 hingga 255) dan sering digunakan untuk mengukur ukuran file atau kapasitas penyimpanan, contohnya **MB** (megabyte) atau **GB** (gigabyte).

Perhatikan perbedaan simbolnya: **`b`** kecil untuk **bit** dan **`B`** besar untuk **byte**.

## 2. Sistem Bilangan Biner

Sistem bilangan biner adalah cara komputer menyimpan dan memproses informasi. Sistem ini hanya menggunakan dua digit, yaitu **0** dan **1**. Semua data, mulai dari teks hingga gambar, pada dasarnya disimpan dalam bentuk deretan panjang angka biner.

## 3. Konversi Biner ke Desimal

Konversi adalah proses mengubah angka biner (deretan 0 dan 1) menjadi angka desimal (angka yang biasa kita gunakan). Aturan utamanya sangat sederhana:

**Setiap digit `1` memiliki nilai yang ditentukan oleh posisinya**, yang dihitung menggunakan **pangkat dari 2**. Setiap digit `0` tidak memiliki nilai, jadi bisa diabaikan.

Posisi dihitung dari kanan ke kiri, dimulai dari $2^0$.

### **Contoh Perhitungan**

Mari kita konversi biner `010101` ke desimal:

| Posisi (dari kanan) | Pangkat 2 | Digit Biner | Perhitungan |
| :---: | :---: | :---: | :---: |
| ke-0 | $2^0 = 1$ | **1** | $1 \times 1 = 1$ |
| ke-1 | $2^1 = 2$ | 0 | (Diabaikan) |
| ke-2 | $2^2 = 4$ | **1** | $1 \times 4 = 4$ |
| ke-3 | $2^3 = 8$ | 0 | (Diabaikan) |
| ke-4 | $2^4 = 16$ | **1** | $1 \times 16 = 16$ |
| ke-5 | $2^5 = 32$ | 0 | (Diabaikan) |

**Hasil Akhir:** Jumlahkan nilai dari semua bit `1`:
$1 + 4 + 16 = 21$

Jadi, **`010101`** dalam biner sama dengan **21** dalam desimal.

----

### **Representasi Angka Negatif dalam Biner**

Dalam komputasi, angka negatif tidak diawali dengan tanda minus (`-`) seperti pada sistem desimal. Sebaliknya, komputer menggunakan metode yang disebut **Two's Complement** untuk merepresentasikan angka negatif.

Metode ini menggunakan bit paling kiri sebagai **bit tanda (sign bit)**:

* **0** untuk angka **positif**.
* **1** untuk angka **negatif**.

### **Langkah-langkah Mengubah Bilangan Positif ke Negatif (Two's Complement)**

1. **Ubah angka positif ke biner** dengan jumlah bit yang ditentukan (misalnya, 8-bit).

      * Contoh: Angka `5` dalam 8-bit biner adalah **`00000101`**.

2. **Balikkan semua bit** (`1` menjadi `0` dan `0` menjadi `1`). Ini disebut **One's Complement**.

      * Dari `00000101` menjadi **`11111010`**.

3. **Tambahkan `1`** pada hasil One's Complement.

      * `11111010 + 1 = 11111011`.
      * Jadi, `-5` dalam 8-bit biner adalah **`11111011`**.

-----

### **Bagaimana Komputer Memahaminya?**

Komputer tidak "mengerti" tanda minus. Bagian dari CPU yang disebut **Arithmetic Logic Unit (ALU)** hanya dirancang untuk melakukan **operasi penjumlahan** (`+`). Dengan sistem Two's Complement, komputer dapat melakukan operasi aritmatika pada angka positif dan negatif secara efisien hanya dengan menggunakan sirkuit penjumlahan.

**Contoh:** Perhitungan $5 + (-5)$

Komputer menjumlahkan biner dari 5 dan -5:

```
  00000101  (5)
+ 11111011  (-5)
----------
 100000000  (hasil)
```

Karena kita menggunakan 8-bit, bit tambahan di paling kiri (bit ke-9) akan **dibuang** atau disebut *overflow*. Hasilnya menjadi **`00000000`**, yang merupakan representasi biner dari angka **0**.

Sistem ini memastikan bahwa penjumlahan antara angka positif dan negatif akan selalu menghasilkan jawaban yang benar secara matematis.
