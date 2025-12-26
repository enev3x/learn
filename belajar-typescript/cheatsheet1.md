### 1. Dasar: Interface vs Class

Ingat bedanya **"Janji"** dan **"Bukti"**.

| Fitur | Interface (`interface`) | Class (`class`) |
| --- | --- | --- |
| **Peran** | **Kontrak/Aturan**. Cuma mendefinisikan bentuk data & nama function. | **Pabrik/Implementasi**. Tempat kodingan logika & data asli disimpan. |
| **Runtime** | Hilang (Cuma buat TS ngecek error). | Ada (Javascript membacanya). |
| **Analogi** | Daftar Menu Restoran. | Dapur & Kokinya. |

```typescript
// Interface (Aturan)
interface Polisi {
  menangkapMaling(): void; // Cuma judul, gak ada isinya
}

// Class (Pelaksana)
class PolisiSektor implements Polisi {
  menangkapMaling() {
    console.log("Dorr! Maling ditangkap."); // Wajib isi sendiri
  }
}

```

---

### 2. Alur Data: Constructor & `this`

Ingat alur masuknya data: **Luar ➡️ Pintu ➡️ Rak**.

* **Constructor**: Pintu Gerbang. Function yang jalan otomatis saat `new` dipanggil.
* **`this`**: Penunjuk ke "Diri Sendiri" (Internal Class).
* **`new`**: Perintah mencetak Class menjadi Object (Alokasi Memori).

```typescript
class User {
  namaInternal: string; // [3] Rak Penyimpanan

  constructor(namaInput: string) { // [1] Pintu Terima Data
    this.namaInternal = namaInput; // [2] Proses Penyimpanan
  }
}

const u = new User("Budi"); // Trigger Constructor

```

---

### 3. Hubungan: Extends vs Implements

| Keyword | Arti | Sifat |
| --- | --- | --- |
| **`implements`** | Menuruti Kontrak | **Kerja Rodi**. Kamu harus nulis ulang semua function yang diminta Interface. |
| **`extends`** | Mewarisi Sifat | **Dapat Warisan**. Kamu dapet semua fitur Parent secara gratis. |

**Aturan `super()`:**
Kalau Class Anak punya constructor sendiri, **WAJIB** panggil `super()` di baris pertama untuk setor data ke Bapak.

```typescript
class Bapak { constructor(public nama: string) {} }

class Anak extends Bapak {
  constructor(nama: string, public mainan: string) {
    super(nama); // Lapor Bapak dulu!
    // Baru urus mainan...
  }
}

```

---

### 4. Dependency Injection (DI) - The Core Logic

Ini jantungnya NestJS. Perubahan pola pikir dari "Mandiri" jadi "Manja".

#### ❌ Cara Kuno (Hardcoded)

Masalah: Class terikat mati. Susah diganti, susah dites.

```typescript
class Mobil {
  constructor() {
    // RIBET: Bikin mesin sendiri di dalem.
    // Kalau mau ganti 'MesinV8', harus bongkar kodingan ini.
    this.mesin = new MesinV8(); 
  }
}

```

#### ✅ Cara Modern (Dependency Injection)

Solusi: Class cuma nyediain colokan. Barang dikirim dari luar.

```typescript
class Mobil {
  // ENAK: Cuma minta. Terserah luar mau kasih mesin apa.
  constructor(mesinDariLuar: IMesin) {
    this.mesin = mesinDariLuar; 
  }
}

```

---

### 5. Access Modifiers (Hak Akses)

* **`public`** 🟢: Bebas. Semua bisa akses.
* **`protected`** 🟡: Keluarga. Cuma Class itu & Anak-anaknya (Turunan).
* **`private`** 🔴: Rahasia. Cuma Class itu sendiri. Anak pun gak boleh tau.

---

### 6. Persiapan Masuk NestJS

Di NestJS nanti, kamu jarang ngetik `new`. Kamu bakal pakai **Decorator** (`@`) dan membiarkan NestJS melakukan **Injection** otomatis.

* **`@Injectable()`**: "Nest, tolong simpan class ini di gudang, siap buat dipinjemin."
* **`@Controller()`**: "Nest, ini class buat ngatur jalur URL."
* **Constructor Injection**:

```typescript
// NestJS Style:
constructor(private userService: UserService) {}
// Artinya: "Nest, tolong suntikin UserService ke sini dong."

```



