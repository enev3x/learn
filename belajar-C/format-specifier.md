
### Struktur Dasar Format Specifier

Format specifier selalu diawali dengan tanda persen (`%`).

#### Contoh dengan `printf()`

```c
int angka = 10;
printf("Nilainya adalah %d\n", angka);
```

  - **`%d`** adalah format specifier untuk mencetak nilai integer.
  - Saat program dijalankan, `%d` akan digantikan oleh nilai variabel `angka`.

#### Contoh dengan `scanf()`

```c
int input_angka;
printf("Masukkan angka: ");
scanf("%d", &input_angka);
```

  - **`%d`** di sini memberi tahu `scanf()` untuk membaca input dari keyboard sebagai integer.
  - Tanda `&` (address-of operator) diperlukan untuk memberi tahu `scanf()` di mana lokasi memori variabel `input_angka` berada.

-----

### Format Specifier Umum

Berikut adalah beberapa format specifier yang paling sering digunakan:

| Specifier | Tipe Data yang Diwakili | Penjelasan |
| :-------- | :---------------------- | :------------------------------------------------------------- |
| `%d` atau `%i` | `int` | Mencetak atau membaca integer desimal (basis 10). |
| `%f` | `float` atau `double` | Mencetak atau membaca bilangan floating-point. |
| `%lf` | `double` | Digunakan secara spesifik untuk `double` di `scanf()` (dan beberapa versi `printf()`). |
| `%c` | `char` | Mencetak atau membaca sebuah karakter tunggal. |
| `%s` | `char*` (string) | Mencetak atau membaca string (array karakter). |
| `%p` | `void*` (pointer) | Mencetak alamat memori dari sebuah variabel dalam format heksadesimal. |
| `%u` | `unsigned int` | Mencetak integer tak bertanda (non-negatif). |
| `%x` atau `%X` | `int` | Mencetak integer dalam format heksadesimal. `%X` menggunakan huruf kapital. |
| `%o` | `int` | Mencetak integer dalam format oktal (basis 8). |

### Mengapa Format Specifier Penting?

Tanpa format specifier, `printf()` tidak akan tahu bagaimana cara menafsirkan bit-bit dari sebuah variabel. Misalnya, nilai 65 bisa ditafsirkan sebagai integer `65`, karakter `'A'` (dalam ASCII), atau bahkan nilai heksadesimal. Format specifier adalah petunjuk yang akurat bagi kompiler untuk menghindari kesalahan interpretasi.



### perbedaan menggunakan %s dan %c dalam format specifier

`printf` di C menggunakan `%c` dan `%s` untuk memberi tahu kompiler bagaimana cara **menginterpretasikan dan menampilkan** data yang diberikan. Ini disebut **specifier format**.

---

### **%c (Character)**

`%c` digunakan untuk menampilkan **satu karakter tunggal**.
* Ketika Anda menggunakan `%c`, `printf` akan mengambil nilai integer dari variabel yang Anda berikan dan menginterpretasikannya sebagai **kode ASCII**. Kemudian, ia akan mencetak karakter yang sesuai dengan kode ASCII tersebut.
* Misalnya, jika Anda ingin mencetak huruf 'A', Anda bisa menulis `printf("Karakternya adalah %c", 'A');`. Di sini, `'A'` memiliki kode ASCII 65, dan `%c` memberitahu `printf` untuk menampilkan karakter yang sesuai, yaitu 'A'. 

---

### **%s (String)**

`%s` digunakan untuk menampilkan **sebuah string** atau **array karakter**.
* String di C adalah **array karakter yang diakhiri dengan null terminator (`\0`)**.
* Ketika `printf` melihat `%s`, ia akan mulai mencetak karakter satu per satu dari alamat memori yang Anda berikan **sampai ia menemukan karakter null terminator (`\0`)**.
* Contohnya, jika Anda memiliki `char nama[] = "Budi";`, string ini sebenarnya disimpan sebagai `'B', 'u', 'd', 'i', '\0'`. Saat Anda menggunakan `printf("Nama saya %s", nama);`, `%s` akan membaca 'B', lalu 'u', 'd', 'i', dan berhenti saat menemukan `\0`, sehingga mencetak "Budi".

---

### **Mengapa format specifier itu penting?**

Tanpa format specifier, `printf` tidak akan tahu bagaimana memperlakukan data yang Anda berikan. Data di memori komputer disimpan sebagai angka biner. `%c` dan `%s` adalah "petunjuk" yang sangat penting bagi `printf` untuk mengubah angka biner tersebut menjadi representasi yang bisa dibaca manusia, entah itu sebagai satu karakter atau sebagai serangkaian karakter yang membentuk kata.
