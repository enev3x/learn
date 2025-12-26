
# 📘 PART 1: Pondasi Dasar (Class & Data)

### 1. Interface vs Class

Ingat beda fungsinya: **Kontrak vs Pabrik**.

| Fitur | Interface (`interface`) | Class (`class`) |
| --- | --- | --- |
| **Fungsi** | Cuma aturan/syarat bentuk data. | Cetakan object yang berisi data & logika. |
| **Runtime** | Hilang saat dijalankan (cuma buat TS). | Tetap ada saat dijalankan (JS paham class). |
| **Analog** | SOP / Daftar Menu. | Karyawan / Dapur. |

```typescript
// KONTRAK (Interface)
interface User {
  name: string;
  id: number;
}

// PABRIK (Class) - Wajib nurut interface
class UserAccount implements User {
  name: string;
  id: number;
  // ... butuh constructor buat isi datanya
}

```

### 2. Constructor & `this`

Ingat alur datanya: **Luar -> Pintu Gerbang -> Rak Penyimpanan**.

* **Constructor:** Function yang otomatis jalan pertama kali pas `new` dipanggil. Tugasnya terima data dari luar.
* **`this`:** Perekat/penunjuk ke object itu sendiri (Internal).

```typescript
class Mobil {
  merkInternal: string; // Rak Penyimpanan

  // Pintu Gerbang (parameter 'm' itu cuma nama sementara)
  constructor(m: string) {
    // "Simpan 'm' ke dalam rak 'merkInternal' milik saya (this)"
    this.merkInternal = m; 
  }
}

const avanza = new Mobil("Toyota"); // "Toyota" masuk ke 'm', lalu ke 'this.merkInternal'

```

### 3. Access Modifiers (Pembatasan)

Siapa yang boleh pegang data/method ini?

1. **`public` (Default):** Bebas. Semua orang boleh akses.
2. **`private`**: **Pelit**. Cuma Class itu sendiri. Anak (turunan) & orang luar gaboleh sentuh.
3. **`protected`**: **Keluarga**. Class itu sendiri & Anak (turunan) boleh akses. Orang luar gaboleh.

---

# 📕 PART 2: Hubungan Antar Class & NestJS Prep

### 4. Extends vs Implements

* **`extends` (Warisan):**
* Hubungan: Bapak ke Anak.
* Efek: **Dapat Gratisan**. Anak mewarisi semua fitur Bapak (kecuali private).
* Keyword: `super()`.


* **`implements` (Kepatuhan):**
* Hubungan: Aturan ke Pelaksana.
* Efek: **Kerja Rodi**. Class harus nulis sendiri semua codingannya sesuai syarat Interface.



### 5. Magic Word: `super()`

Wajib dipakai kalau **Class Anak punya Constructor sendiri**.

* **Logika:** "Jalanin dulu constructor Bapak (pondasi), baru jalanin constructor Anak (lantai 2)."
* **Alur Data:** Data dilempar dari Anak -> Naik ke Bapak.

```typescript
class Bapak {
  constructor(public nama: string) {}
}

class Anak extends Bapak {
  mainan: string;
  constructor(nama: string, mainan: string) {
    super(nama); // Lempar 'nama' ke Bapak buat diurus
    this.mainan = mainan; // 'mainan' diurus sendiri
  }
}

```

### 6. Method & Void

Di Interface/Class, function bisa punya tipe kembalian.

* **`: void`** -> Cuma aksi (ubah database, print log). Gak ngasilin nilai balik.
* **`: number/string`** -> Kalkulasi/Ambil data. Wajib ada kata `return`.

### 7. Persiapan Mental NestJS

Dua konsep yang bukan sihir tapi "shortcut":

* **Decorator (`@`)**: Stiker/Label buat ngasih tau sistem fungsi class tersebut.
* Contoh: `@Controller` (Ini pengatur jalan), `@Get` (Ini buat nerima request).


* **Dependency Injection (DI)**: Jangan bikin object sendiri (`new Service()`). Minta aja sama Nest di constructor, nanti disuapin otomatis.

```typescript
// GAYA NESTJS
constructor(private service: KucingService) {
  // Gak perlu 'new KucingService()'
  // Langsung pake: this.service.meong()
}

```



