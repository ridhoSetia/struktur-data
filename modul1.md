## 1. Apa itu Kompleksitas Algoritma?

Bayangkan kamu punya banyak cara untuk menyelesaikan satu masalah (misalnya, puluhan cara untuk *sorting* data). Sebuah algoritma tidak cuma harus **benar**, tapi juga harus **mangkus** (efisien).

Efisiensi itu diukur dari dua hal:

* **Kompleksitas Waktu ($T(n)$):** Berapa banyak tahapan komputasi yang dilakukan? 


* **Kompleksitas Ruang ($S(n)$):** Berapa banyak memori yang dimakan oleh struktur datamu? 



> 
> "Bikin kode yang jalan itu gampang, tapi bikin kode yang nggak bikin komputer *hang* saat datanya ada 1 juta itu baru tantangan." 
> 
> 

---

## 2. Kenapa Tidak Pakai Stopwatch Saja?

Jawabannya: **Tidak akurat.** Karena:

1. **Spek Komputer Beda:** Komputer Core i9 pasti lebih cepat dari Core i3.


2. **Compiler Beda:** Hasil optimasi setiap bahasa/compiler itu tidak sama.

Jadi, kita pakai model abstrak yang disebut **Notasi Big-O** agar pengukurannya adil tanpa peduli mesinnya apa.

---

## 3. Cara Menghitung (Studi Kasus: FindMax)

Cara menghitungnya adalah dengan melihat **operasi dasarnya** (biasanya di dalam *looping*).

* **Best Case ($T_{min}$):** Kondisi saat data sangat menguntungkan sehingga operasi tertentu tidak perlu dijalankan.


* **Worst Case ($T_{max}$):** Kondisi saat data paling buruk sehingga komputer harus bekerja maksimal.



Dari perhitungan di modul, algoritma `FindMax` memiliki kompleksitas **$O(n)$** karena jumlah operasinya meningkat secara linear (sebanding) dengan jumlah input $n$.

---

## 4. Spektrum Kompleksitas (Dari Cepat ke Lambat)

Ini bagian paling penting buat kalian. Urutannya adalah:

| Notasi | Nama | Penjelasan Singkat |
| --- | --- | --- |
| **$O(1)$** | Konstan | Paling cepat. Mau datanya 1 atau 1 juta, waktunya tetap sama (contoh: tukar nilai variabel).
| **$O(\log n)$** | Logaritmik | Sangat efisien. Biasanya untuk algoritma yang membagi masalah jadi kecil (contoh: *Binary Search*).
| **$O(n)$** | Linear | Waktu naik sesuai jumlah data (contoh: *Sequential Search*).
| **$O(n^2)$** | Kuadratik | Mulai lambat. Biasanya karena ada *looping* di dalam *looping*.
| **$O(2^n)$** | Eksponensial | Sangat buruk/lambat. Jangan dipakai untuk data besar.

---


* **Sequential Search ($O(n)$):** Seperti mencari buku di rak satu per satu dari ujung ke ujung. Kalau ada 1000 buku, ya cek 1000 kali.


* **Binary Search ($O(\log n)$):** Seperti mencari kata di kamus. Kamu buka tengahnya, lalu buang setengah yang tidak perlu. Jauh lebih cepat!.


## 5. Apa itu "Cost" (Biaya)?

Bayangkan setiap baris kode adalah sebuah jasa yang harus kita bayar dengan waktu.

* **$C_1, C_2, C_3, \dots$**: Ini adalah simbol biaya (waktu) konstan untuk setiap jenis operasi (seperti mengisi nilai, membandingkan angka, atau memanggil fungsi).


* Nilai aslinya bisa berbeda-beda tergantung komputer, tapi dalam analisis algoritma, kita anggap setiap baris punya bobot biaya tertentu.



## 6. Bedah Tabel Kompleksitas (FindMax)

mari kite melihat baris demi baris pada algoritma mencari nilai maksimal:

| Baris Kode | Cost | Berapa Kali Jalan? | Penjelasan Logika |
| --- | --- | --- | --- |
| `max = A[0]` | $C_2$ | $1$ | Hanya dilakukan sekali di awal.
| `for i = 1 to n-1` | $C_3$ | $n$ | Perulangan mengecek kondisi sebanyak $n$ kali (termasuk cek terakhir untuk berhenti).
| `if A[i] > max` | $C_4$ | $n-1$ | Isi di dalam perulangan dijalankan sebanyak jumlah data dikurangi satu.
| `max = A[i]` | $C_5$ | $0$ atau $n-1$ | Ini tergantung apakah datanya sudah urut atau tidak.

---

## 7. Menghitung Total Waktu ($T_n$)

total waktu adalah hasil kali antara **Cost** dengan **Berapa kali baris itu dijalankan**.

### A. Kasus Terbaik (Best Case - $T_{min}$)

Terjadi jika angka terbesar ada di posisi pertama (`A[0]`).

* Kondisi `if` akan selalu **salah**, jadi baris `max = A[i]` tidak pernah dijalankan (Cost = 0).


* Hasilnya: $T(n) = 4n + 4$ (Fungsi Linear).


* Notasi: **$O(n)$**.



### B. Kasus Terburuk (Worst Case - $T_{max}$)

Terjadi jika angka terbesar ada di posisi paling akhir, atau data urut membesar.

* Kondisi `if` akan selalu **benar**, jadi setiap perulangan kita harus memperbarui nilai `max`.


* Hasilnya: $T(n) = 5n + 3$ (Tetap Fungsi Linear).


* Notasi: **$O(n)$**.



---

## 8. Teorema Suku Dominan

gak perlu pusing dengan angka $+4$ atau $+3$ di belakang rumus. Sesuai **Teorema**, kita hanya mengambil pangkat tertinggi (suku dominan):

* $T(n) = 5n + 3 \rightarrow$ pangkat tertingginya adalah $n^1$, jadi **$O(n)$**.


* $T(n) = 3n^3 + 2n^2 + 10 \rightarrow$ pangkat tertingginya adalah $n^3$, jadi **$O(n^3)$**.



---

## 9. Ringkasan Spektrum Kompleksitas

jadi mana yang "aman" dan mana yang "berbahaya" untuk aplikasi: 

1. **$O(1)$ & $O(\log n)$**: Sangat Efisien. Contoh: Penukaran variabel atau pencarian biner.


2. **$O(n)$**: Standar. Waktu naik sejajar dengan data.


3. **$O(n^2)$ & $O(n^3)$**: Mulai berat. Jika data $n=1000$, $O(n^2)$ butuh 1 juta operasi.


4. **$O(2^n)$ & $O(n!)$**: Sangat Buruk. Biasanya untuk metode *Brute Force*. Jika data bertambah sedikit saja, waktu tunggunya bisa naik berlipat-lipat ganda.