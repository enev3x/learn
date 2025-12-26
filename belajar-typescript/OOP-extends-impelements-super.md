
# 📒 Catatan OOP: Extends, Implements, & Super

### 1. Implements (Kepatuhan / Kontrak)

> **Konsep:** "Saya berjanji akan memenuhi semua syarat yang diminta."

* **Hubungan:** Interface ➡️ Class.
* **Sifat:** **Kerja Rodi**. Kamu tidak dapat kodingan apa-apa. Kamu cuma dikasih daftar tugas (nama function/variable) yang **WAJIB** kamu tulis sendiri kodingannya di dalam class.
* **Keyword:** `implements`.

```typescript
interface SyaratKasir {
  hitung(): number; // Syarat
}

// Class WAJIB nulis logic 'hitung' sendiri
class Indomaret implements SyaratKasir {
  hitung() { 
    return 1000 + 2000; 
  }
}

```

### 2. Extends (Warisan / Hak Milik)

> **Konsep:** "Saya adalah anak dari Bapak itu, jadi saya punya apa yang Bapak punya."

* **Hubungan:** Class (Parent) ➡️ Class (Child).
* **Sifat:** **Dapat Gratisan**. Semua method & property milik Parent (kecuali private) otomatis jadi milik Child. Gak perlu tulis ulang.
* **Keyword:** `extends`.

```typescript
class Bapak {
  motor = "Supra X";
  nasehat() { console.log("Rajin menabung!"); }
}

// Anak otomatis punya 'motor' dan bisa 'nasehat()'
class Anak extends Bapak {}

```

### ⚔️ Perbedaan Utama (Extends vs Implements)

| Fitur | EXTENDS | IMPLEMENTS |
| --- | --- | --- |
| **Analogi** | Bapak ke Anak (DNA) | SOP ke Karyawan (Aturan) |
| **Kode** | Mewarisi kode yang sudah jadi | Harus nulis kode sendiri dari nol |
| **Jumlah** | Cuma boleh 1 Parent | Boleh banyak Interface |
| **Tujuan** | Menambah fitur dari yang sudah ada | Memastikan struktur data standar |

---

### 3. Super (Jalur Komunikasi ke Atas)

> **Konsep:** "Pak (Parent), ini data titipan buat Bapak, tolong diurus dulu ya (karena Bapak pondasinya)."

* **Kapan Dipakai?** Wajib dipakai saat Class Child punya **Constructor Sendiri**.
* **Fungsi:** Mengirim parameter dari Child ke Constructor Parent.
* **Posisi:** Wajib di baris **PERTAMA** di dalam constructor.

**Contoh Kasus:**
Parent butuh `nama`. Child butuh `nama` & `sekolah`.

```typescript
class Manusia { // Parent
  constructor(public nama: string) {
    // Parent mengurus nama
  }
}

class Pelajar extends Manusia { // Child
  constructor(nama: string, public sekolah: string) {
    // 1. LEMPAR KE ATAS (Wajib)
    // Kirim 'nama' ke constructor Manusia
    super(nama); 
    
    // 2. URUS SISANYA
    // 'sekolah' otomatis diurus Pelajar (karena ada 'public')
  }
}

```

**Rumus Hafalan `super()`:**

1. Kalau Anak **gak punya** constructor -> Gak perlu `super` (Otomatis nebeng Bapak).
2. Kalau Anak **punya** constructor -> **WAJIB** `super()`.


