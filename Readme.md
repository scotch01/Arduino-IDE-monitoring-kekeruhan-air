# Monitoring Kekeruhan Air

Ini adalah code untuk monitoring kekruhan air yang akan mengirimkan data ke database

<ul>
  <li> Jika nilai sensor analog diatas 50, maka status air adalah bersih </li>
  <li> Jika nilai sensor analog diatas 30 tetapi dibawah 50, maka status air adalah keruh </li>
  <li> Jika nilai sensor analog dibawah 30, maka status air adalah kotor</li>
</ul>

nb : Untuk menggunakan ini, wajib menyertakan folder monitoring atau file monitoring.ino ini harus terdapat didalam folder bernama "monitoring" karena jika tidak, tidak dapat terbaca oleh Arduino IDE
