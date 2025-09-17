# Catatan: Perbedaan `char *` dan `char []` dalam C

Dalam bahasa pemrograman C, ada dua cara umum untuk menginisialisasi string. Meskipun keduanya terlihat mirip dan bisa digunakan untuk tujuan yang sama, mereka memiliki perbedaan fundamental terkait **cara mereka disimpan di memori**.

---

### 1. `char header[]` (Array)

Ketika kamu mendeklarasikan string menggunakan array, **data string itu sendiri disimpan secara langsung** di dalam sebuah blok memori. Nama variabel `header` adalah nama dari blok memori itu, dan nama ini secara implisit mewakili alamat memori awal dari string.

* **Apa yang disimpan:** String literal (misalnya "hello world") disimpan di dalam blok memori yang dialokasikan untuk array.
* **Sifat:** Array adalah blok memori tetap. Ukurannya sudah ditentukan saat kompilasi. Kamu **tidak bisa mengubahnya** untuk menunjuk ke string lain setelah diinisialisasi.

---

### 2. `char *header` (Pointer)

Ketika kamu menggunakan pointer, situasinya berbeda. Variabel `header` itu sendiri tidak menyimpan string, melainkan hanya menyimpan **alamat memori** dari string tersebut. String literal "HTTP/1.1 200 OK" disimpan di lokasi memori yang terpisah, dan pointer `*header` hanya "menunjuk" ke alamat tersebut.

* **Apa yang disimpan:** Variabel `header` menyimpan alamat memori sebagai sebuah angka (misalnya, `415325` atau `547362942671452`).
* **Sifat:** Pointer sangat fleksibel. Kamu **bisa mengubah nilai `header`** untuk menunjuk ke string lain yang berada di lokasi memori berbeda.

---

### Perbandingan Sederhana

| Fitur | `char header[]` (Array) | `char *header` (Pointer) |
| :--- | :--- | :--- |
| **Penyimpanan Data** | Data string disimpan langsung di dalam array. | Data string disimpan di lokasi memori lain. Pointer hanya menyimpan alamatnya. |
| **Fleksibilitas** | Tidak bisa diubah untuk menunjuk ke string lain. | Sangat fleksibel. Bisa diubah untuk menunjuk ke string lain kapan saja. |
| **Digunakan untuk** | String yang isinya bisa diubah (modifikasi karakter). | String konstan yang hanya untuk dibaca (*read-only*). |

---

### Hubungan dengan `write()`

Seperti yang kita bahas sebelumnya, fungsi `write()` membutuhkan alamat memori awal dari data yang akan ditulis. Baik array maupun pointer, nama variabelnya dapat digunakan karena **keduanya merepresentasikan alamat awal** dari string.

* Pada `write(1, header, strlen(header))`, `header` mewakili alamat awal dari array `header[]`.
* Pada `write(1, header, 13)`, `header` adalah pointer yang sudah menyimpan alamat awal string (`54736...`).

Meskipun terlihat sama, di balik layar, cara komputer mengelola memori untuk kedua deklarasi ini sangat berbeda.

### Apa itu `strlen()`?

`strlen()` adalah fungsi standar di bahasa C yang digunakan untuk menghitung panjang sebuah string. Cara kerjanya sangat sederhana: **ia akan menghitung setiap karakter dalam string, satu per satu, sampai ia menemukan karakter khusus yang disebut *null terminator* (`\0`)**.

  * Null terminator ini adalah karakter yang menandakan akhir dari sebuah string di C.
  * `strlen()` tidak menghitung `\0` ini dalam total panjang string.

-----

### Mengapa `strlen()` Dianggap Lambat?

`strlen()` dianggap lambat karena memiliki kompleksitas waktu **O(n)**, di mana `n` adalah panjang string. Ini berarti waktu yang dibutuhkan untuk menjalankan fungsi ini **berbanding lurus dengan panjang string**.

Bayangkan kamu memiliki string dengan 1 miliar karakter. Untuk mengetahui panjangnya, `strlen()` harus memeriksa setiap karakter, dari yang pertama sampai yang ke-1.000.000.000, hanya untuk menemukan `\0`. Jika kamu melakukan ini berulang kali dalam sebuah *loop*, performanya bisa sangat menurun.

-----

### Pengganti dan Best Case

Pengganti terbaik untuk `strlen()` adalah dengan **menyimpan panjang string itu sendiri** dalam sebuah variabel saat string dibuat atau dimodifikasi. Dengan begitu, kamu tidak perlu menghitung ulang panjangnya setiap kali dibutuhkan.

Sebagai contoh, fungsi `write()` yang kita bahas sebelumnya adalah contoh yang bagus. Ia menerima panjang string sebagai argumen terpisah.

```c
// Cara ini lebih efisien karena panjangnya sudah diketahui.
// write(1, my_string, my_string_length);
```

**Kapan `strlen()` adalah pilihan terbaik (Best Case)?**
`strlen()` tetap menjadi pilihan yang tepat ketika:

1.  **String sangat pendek**.
2.  Kamu **tidak tahu panjang string sebelumnya** dan tidak ada cara lain untuk mendapatkannya selain dengan menghitung.
3.  Kamu hanya memanggilnya **sekali** dan tidak di dalam sebuah *loop* yang berulang-ulang.
