<html>

<head>
    <title>Index</title>
</head>

<body>
    <h1>Clock Conversion Form</h1>
    <form method="post" action="">
        <label for="clock">Hours:</label>
        <input type="number" name="clock" id="clock" min="0" max="23" required><br><br>

        <label for="minut">Minutes:</label>
        <input type="number" name="minut" id="minut" min="0" max="59" required><br><br>

        <input type="submit" value="Convert">
    </form>

    <?php
    error_reporting(0);

    interface TimeToWordConvertingInterface
    {
        public function convert(int $hours, int $minutes): string;
    }

    class TimeToWordConverter implements TimeToWordConvertingInterface
    {
        public function convert(int $hours, int $minutes): string
        {
            $hourWords = [
                1 => 'од',
                2 => 'дв',
                3 => 'тр',
                4 => 'четыре',
                5 => 'пят',
                6 => 'шест',
                7 => 'сем',
                8 => 'вос',
                9 => 'девят',
                10 => 'десят',
                11 => 'одиннадцат',
                12 => 'двенадцат'
            ];
            $minuteWords = [
                1 => 'одна минута',
                2 => 'две минуты',
                3 => 'три минуты',
                4 => 'четыре минуты',
                5 => 'пять минут',
                6 => 'шесть минут',
                7 => 'семь минут',
                8 => 'восемь минут',
                9 => 'девять минут',
                10 => 'десять минут',
                11 => 'одиннадцать минут',
                12 => 'двенадцать минут',
                13 => 'тринадцать минут',
                14 => 'четырнадцать минут',
                15 => 'четверть',
                16 => 'шестнадцать минут',
                17 => 'семнадцать минут',
                18 => 'восемнадцать минут',
                19 => 'девятнадцать минут',
                20 => 'двадцать минут',
                21 => 'двадцать одна минута',
                22 => 'двадцать две минуты',
                23 => 'двадцать три минуты',
                24 => 'двадцать четыре минуты',
                25 => 'двадцать пять минут',
                26 => 'двадцать шесть минут',
                27 => 'двадцать семь минут',
                28 => 'двадцать восемь минут',
                29 => 'двадцать девять минут',
                30 => 'половина'
            ];

            $hour = $hourWords[$hours];
            $minute = $minuteWords[$minutes];

            // if($minutes && $hours) {}
            if ($minutes == 0) {
                if ($hours == 1) return $hour . "ин час";
                if ($hours == 2) return $hour . "а часа";
                if ($hours == 3) return $hour . "и часа";
                if ($hours == 4) return $hour . "часа";
                if ($hours == 5 || $hours == 6 || $hours == 7 || $hours == 9 || $hours == 10 || $hours == 11 || $hours == 12) return $hour . "ь часов";
                if ($hours == 8) return $hour . "емь часов";
            }

            if ($minutes == 1 && $hours >= 5 && $hours <= 12 && $hours != 8) return $minute . " после " . $hour . "и";
            if ($minutes == 1 && $hours == 8) return $minute . " после " . $hour . "ьми";

            if ($minutes >= 1 && $minutes < 30 && $minutes != 15 && $hours < 5) {
                if ($hours == 1) return $minute . " после часа";
                if ($hours == 2) return $minute . " после двух";
                if ($hours == 3) return $minute . " после трех";
                if ($hours == 4) return $minute . " после четырех";
                if ($hours == 5) return $minute . " после пяти";
            }
            if ($minutes == 15) {
                if ($hours == 1) return $minute . " второго";
                if ($hours == 2) return $minute . " третьего";
                if ($hours == 3) return $minute . " четвертого";
                if ($hours == 4) return $minute . " пятого";
                if ($hours == 5) return $minute . " шестого";
                if ($hours == 6) return $minute . " седьмого";
                if ($hours == 7) return $minute . " восьмого";
                if ($hours == 8) return $minute . " девятого";
                if ($hours == 9) return $minute . " десятого";
                if ($hours == 10) return $minute . " одиннадцатого";
                if ($hours == 11) return $minute . " двенадцатого";
                if ($hours == 12) return $minute . " первого";
            }
            if ($minutes == 59) {
                if ($hours == 0) return $minuteWords[60 - $minutes] . " до часа";
                if ($hours == 1) return $minuteWords[60 - $minutes] . " до двух";
                if ($hours == 2) return $minuteWords[60 - $minutes] . " до трех";
                if ($hours == 3) return $minuteWords[60 - $minutes] . " до четырех";
                if ($hours == 4) return $minuteWords[60 - $minutes] . " до пяти";
                if ($hours == 5) return $minuteWords[60 - $minutes] . " до шести";
                if ($hours == 6) return $minuteWords[60 - $minutes] . " до семи";
                if ($hours == 7) return $minuteWords[60 - $minutes] . " до восьми";
                if ($hours == 8) return $minuteWords[60 - $minutes] . " до девяти";
                if ($hours == 9) return $minuteWords[60 - $minutes] . " до десяти";
                if ($hours == 10) return $minuteWords[60 - $minutes] . " до одиннадцати";
                if ($hours == 11) return $minuteWords[60 - $minutes] . " до двенадцати";
                if ($hours == 12) return $minuteWords[60 - $minutes] . " до часа";
            }

            if ($minutes < 30 && $hours >= 5 && $hours <= 12 && $hours != 8)    return $minute . " после " . $hour . "и";
            if ($minutes < 30 && $hours == 8) return $minute . " после " . $hour . "ьми";

            if ($minutes == 30) {
                if ($hours == 1) return $minute . " второго";
                if ($hours == 2) return $minute . " третьего";
                if ($hours == 3) return $minute . " четвертого";
                if ($hours == 4) return $minute . " пятого";
                if ($hours == 5) return $minute . " шестого";
                if ($hours == 6) return $minute . " седьмого";
                if ($hours == 7) return $minute . " восьмого";
                if ($hours == 8) return $minute . " девятого";
                if ($hours == 9) return $minute . " десятого";
                if ($hours == 10) return $minute . " одиннадцатого";
                if ($hours == 11) return $minute . " двенадцатого";
                if ($hours == 12) return $minute . " первого";
            }

            if ($minutes == 45) {
                if ($hours == 1) return "пятнадцать минут до двух";
                if ($hours == 2) return "пятнадцать минут до трех";
                if ($hours == 3) return "пятнадцать минут до четырех";
                if ($hours == 4) return "пятнадцать минут до пяти";
                if ($hours == 5) return "пятнадцать минут до шести";
                if ($hours == 6) return "пятнадцать минут до семи";
                if ($hours == 7) return "пятнадцать минут до восьми";
                if ($hours == 8) return "пятнадцать минут до девяти";
                if ($hours == 9) return "пятнадцать минут до десяти";
                if ($hours == 10) return "пятнадцать минут до одиннадцати";
                if ($hours == 11) return "пятнадцать минут до двенадцати";
                if ($hours == 12) return "пятнадцать минут до часа";
            }
            if ($minutes > 30 && ($hours % 12) + 1 >= 5 && ($hours % 12) + 1 <= 12 && ($hours % 12) + 1 != 8) {
                return $minuteWords[60 - $minutes] . " до " . $hourWords[($hours % 12) + 1] . "и";
            }
            if ($minutes > 30 && ($hours % 12) + 1 < 5) {
                if ($hours == 1) return $minuteWords[60 - $minutes] . " до двух";
                if ($hours == 2) return $minuteWords[60 - $minutes] . " до трех";
                if ($hours == 3) return $minuteWords[60 - $minutes] . " до четырех";
                if ($hours == 4) return $minuteWords[60 - $minutes] . " до пяти";
            }
            if ($minutes > 30 && ($hours % 12) + 1 == 8) {
                return $minuteWords[60 - $minutes] . " до " . $hourWords[($hours % 12) + 1] . "ьми";
            }
            $minute = $minuteWords[60 - $minutes];
            return $minute . " до часа";
        }
    }


    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $hours = $_POST['clock'];
        $minutes = $_POST['minut'];
        $converter = new TimeToWordConverter();
        $result = $converter->convert($hours, $minutes);

        echo "$result</p>";
    }
    ?>

</body>

</html>