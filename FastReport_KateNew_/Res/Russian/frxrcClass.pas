{******************************************}
{                                          }
{             FastReport v4.0              }
{          Language resource file          }
{                                          }
{         Copyright (c) 1998-2008          }
{         by Alexander Tzyganenko,         }
{            Fast Reports Inc.             }
{                                          }
{******************************************}

unit frxrcClass;

interface

implementation

uses frxRes;

const resXML =
'<?xml version="1.1" encoding="utf-8"?><Resources CodePage="1251"><StrRes Name="1" Text="ОК"/><StrRes Name="2" Text="Отмена"/><StrRes Name="3" ' + 
'Text="Все"/><StrRes Name="4" Text="Текущая"/><StrRes Name="5" Text="Номера:"/><StrRes Name="6" Text="Разрывы страниц"/><' + 
'StrRes Name="7" Text="Страницы"/><StrRes Name="8" Text="Опции"/><StrRes Name="9" Text="Введите номера и/или диапаз' + 
'оны страниц, разделенные запятыми. Например, 1,3,5-12"/><StrRes Name="100" Text="Предварительный �' + 
'�росмотр"/><StrRes Name="101" Text="Печать"/><StrRes Name="102" Text="Печать"/><StrRes Name="103" Text="Открыть"/><StrRes Na' + 
'me="104" Text="Открыть"/><StrRes Name="105" Text="Сохранить"/><StrRes Name="106" Text="Сохранить"/><StrRes Name="107" Text="�' + 
'�кспорт"/><StrRes Name="108" Text="Экспорт"/><StrRes Name="109" Text="Найти"/><StrRes Name="110" Text="Найти"/><StrRes Name="11' + 
'1" Text="Целиком"/><StrRes Name="112" Text="Страница целиком"/><StrRes Name="113" Text="По ширине"/><StrRes Name="114" T' + 
'ext="По ширине"/><StrRes Name="115" Text="100%"/><StrRes Name="116" Text="100%"/><StrRes Name="117" Text="Две страницы"/><StrRes Na' + 
'me="118" Text="Две страницы"/><StrRes Name="119" Text="Масштаб"/><StrRes Name="120" Text="Поля"/><StrRes Name="121" Text="Сво' + 
'йства страницы"/><StrRes Name="122" Text="Дерево"/><StrRes Name="123" Text="Дерево отчета"/><StrRes Name="124" Text="У' + 
'величить"/><StrRes Name="125" Text="Увеличить"/><StrRes Name="126" Text="Уменьшить"/><StrRes Name="127" Text="Уменьши' + 
'ть"/><StrRes Name="128" Text="Дерево"/><StrRes Name="129" Text="Дерево отчета"/><StrRes Name="130" Text="Миниатюры"/><Str' + 
'Res Name="131" Text="Миниатюры"/><StrRes Name="132" Text="Правка"/><StrRes Name="133" Text="Редактировать страницу' + 
'"/><StrRes Name="134" Text="Первая"/><StrRes Name="135" Text="На первую страницу"/><StrRes Name="136" Text="Предыдущая' + 
'"/><StrRes Name="137" Text="На предыдущую страницу"/><StrRes Name="138" Text="Следующая"/><StrRes Name="139" Text="На �' + 
'�ледующую страницу"/><StrRes Name="140" Text="Последняя"/><StrRes Name="141" Text="На последнюю страницу"/' + 
'><StrRes Name="142" Text="Номер страницы"/><StrRes Name="150" Text="Во весь экран"/><StrRes Name="151" Text="Сохранит�' + 
'� в PDF"/><StrRes Name="152" Text="Отослать по E-mail"/><StrRes Name="zmPageWidth" Text="По ширине"/><StrRes Name="zmWholePage" Tex' + 
't="Страница целиком"/><StrRes Name="200" Text="Печать"/><StrRes Name="201" Text="Принтер"/><StrRes Name="202" Text="Стр' + 
'аницы"/><StrRes Name="203" Text="Количество"/><StrRes Name="204" Text="Разобрать по копиям"/><StrRes Name="205" Text="' + 
'Копии"/><StrRes Name="206" Text="Печатать"/><StrRes Name="207" Text="Прочее"/><StrRes Name="208" Text="Где:"/><StrRes Name="209"' + 
' Text="Свойства..."/><StrRes Name="210" Text="Печать в файл"/><StrRes Name="211" Text="Порядок"/><StrRes Name="212" Text="И' + 
'мя:"/><StrRes Name="213" Text="Режим печати"/><StrRes Name="214" Text="Печатать на листе"/><StrRes Name="216" Text="Дуп' + 
'лекс"/><StrRes Name="ppAll" Text="Все страницы"/><StrRes Name="ppOdd" Text="Нечетные страницы"/><StrRes Name="ppEven" T' + 
'ext="Четные страницы"/><StrRes Name="pgDefault" Text="По умолчанию"/><StrRes Name="pmDefault" Text="По умолчанию"/' + 
'><StrRes Name="pmSplit" Text="Разрезать большие страницы"/><StrRes Name="pmJoin" Text="Объединять маленькие' + 
' страницы"/><StrRes Name="pmScale" Text="Масштабировать"/><StrRes Name="poDirect" Text="Прямой (1-9)"/><StrRes Name="poRev' + 
'erse" Text="Обратный (9-1)"/><StrRes Name="300" Text="Искать текст"/><StrRes Name="301" Text="Текст:"/><StrRes Name="302" Text' + 
'="Настройки поиска"/><StrRes Name="303" Text="Заменить"/><StrRes Name="304" Text="Искать с начала"/><StrRes Name="' + 
'305" Text="Различать регистр"/><StrRes Name="400" Text="Настройки страницы"/><StrRes Name="401" Text="Ширина"/>' + 
'<StrRes Name="402" Text="Высота"/><StrRes Name="403" Text="Размер"/><StrRes Name="404" Text="Ориентация"/><StrRes Name="405" Tex' + 
't="Левое"/><StrRes Name="406" Text="Верхнее"/><StrRes Name="407" Text="Правое"/><StrRes Name="408" Text="Нижнее"/><StrRes Name' + 
'="409" Text="Поля"/><StrRes Name="410" Text="Портретная"/><StrRes Name="411" Text="Альбомная"/><StrRes Name="412" Text="Про�' + 
'�ее"/><StrRes Name="413" Text="Применить к текущей странице"/><StrRes Name="414" Text="Применить ко всем с�' + 
'�раницам"/><StrRes Name="500" Text="Печать"/><StrRes Name="501" Text="Принтер"/><StrRes Name="502" Text="Страницы"/><StrRe' + 
's Name="503" Text="Копии"/><StrRes Name="504" Text="Количество"/><StrRes Name="505" Text="Опции"/><StrRes Name="506" Text="ESC-к�' + 
'�манды"/><StrRes Name="507" Text="Печать в файл"/><StrRes Name="508" Text="OEM-кодировка"/><StrRes Name="509" Text="Псев�' + 
'�ографика"/><StrRes Name="510" Text="Файл печати (*.prn)|*.prn"/><StrRes Name="mbConfirm" Text="Подтверждение"/><StrRes' + 
' Name="mbError" Text="Ошибка"/><StrRes Name="mbInfo" Text="Информация"/><StrRes Name="xrCantFindClass" Text="Не удалось на�' + 
'�ти класс"/><StrRes Name="prVirtual" Text="Виртуальный"/><StrRes Name="prDefault" Text="По умолчанию"/><StrRes Name="prCu' + 
'stom" Text="Пользовательский"/><StrRes Name="enUnconnHeader" Text="Не подключенный header/footer"/><StrRes Name="enUncon' + 
'nGroup" Text="Нет дата-бэнда для группы"/><StrRes Name="enUnconnGFooter" Text="Нет заголовка группы"/><StrRes N' + 
'ame="enBandPos" Text="Неправильно расположен бэнд:"/><StrRes Name="dbNotConn" Text="Компонент %s не подключ' + 
'ен к данным"/><StrRes Name="dbFldNotFound" Text="Поле не найдено:"/><StrRes Name="clDSNotIncl" Text="(компонент не в' + 
'ключен в Report.DataSets)"/><StrRes Name="clUnknownVar" Text="Неизвестная переменная или поле БД:"/><StrRes Name=' + 
'"clScrError" Text="Ошибка в скрипте %s: %s"/><StrRes Name="clDSNotExist" Text="Набор данных &#38;#34;%s&#38;#34; не най�' + 
'�ен"/><StrRes Name="clErrors" Text="Были обнаружены следующие ошибки:"/><StrRes Name="clExprError" Text="Ошибка �' + 
'� выражении"/><StrRes Name="clFP3files" Text="Готовый отчет"/><StrRes Name="clComprPreparedRepFilter" Text="Compressed prepared r' + 
'eport (*.fp3)|*.fp3"/><StrRes Name="clSaving" Text="Сохраняется файл..."/><StrRes Name="clCancel" Text="Отмена"/><StrRes Name="cl' + 
'Close" Text="Закрыть"/><StrRes Name="clPrinting" Text="Печатается страница"/><StrRes Name="clLoading" Text="Загружае�' + 
'�ся файл..."/><StrRes Name="clPageOf" Text="Страница %d из %d"/><StrRes Name="clOf" Text="из %d"/><StrRes Name="clFirstPass" Text="�' + 
'�ервый проход: страница "/><StrRes Name="clNoPrinters" Text="В вашей системе не установлено принте�' + 
'�ов"/><StrRes Name="clDecompressError" Text="Ошибка распаковки данных"/><StrRes Name="crFillMx" Text="Заполняется c' + 
'ross-tab..."/><StrRes Name="crBuildMx" Text="Строится cross-tab..."/><StrRes Name="prRunningFirst" Text="Первый проход: стран' + 
'ица %d"/><StrRes Name="prRunning" Text="Готовится страница %d"/><StrRes Name="prPrinting" Text="Печатается страни�' + 
'�а %d"/><StrRes Name="prExporting" Text="Экспорт страницы %d"/><StrRes Name="uCm" Text="см"/><StrRes Name="uInch" Text="in"/><StrRes' + 
' Name="uPix" Text="px"/><StrRes Name="uChar" Text="chr"/><StrRes Name="dupDefault" Text="По умолчанию"/><StrRes Name="dupVert" Text="Вер' + 
'тикальный"/><StrRes Name="dupHorz" Text="Горизонтальный"/><StrRes Name="dupSimpl" Text="Не использовать"/><StrRes' + 
' Name="SLangNotFound" Text="Язык ''%s'' не найден"/><StrRes Name="SInvalidLanguage" Text="Ошибка в описании языка"/><Str' + 
'Res Name="SIdRedeclared" Text="Идентификатор переопределен: "/><StrRes Name="SUnknownType" Text="Неизвестный ти' + 
'п: "/><StrRes Name="SIncompatibleTypes" Text="Несовместимые типы"/><StrRes Name="SIdUndeclared" Text="Неопределенный �' + 
'�дентификатор: "/><StrRes Name="SClassRequired" Text="Ожидается класс"/><StrRes Name="SIndexRequired" Text="Ожидаетс' + 
'я индекс"/><StrRes Name="SStringError" Text="Строка не имеет свойств или методов"/><StrRes Name="SClassError" Tex' + 
't="Класс %s не содержит свойства по умолчанию"/><StrRes Name="SArrayRequired" Text="Ожидается массив"' + 
'/><StrRes Name="SVarRequired" Text="Ожидается переменная"/><StrRes Name="SNotEnoughParams" Text="Недостаточно пара�' + 
'�етров"/><StrRes Name="STooManyParams" Text="Слишком много параметров"/><StrRes Name="SLeftCantAssigned" Text="Левая �' + 
'�асть выражения не может быть присвоена"/><StrRes Name="SForError" Text="Переменная цикла FOR долж' + 
'на быть числовой"/><StrRes Name="SEventError" Text="Обработчик события должен быть процедурой"/><St' + 
'rRes Name="600" Text="Раскрыть все"/><StrRes Name="601" Text="Свернуть все"/><StrRes Name="clStrNotFound" Text="Текст не ' + 
'найден"/><StrRes Name="clCantRen" Text="Невозможно переименовать %s, объект был объявлен в родите' + 
'льском отчёте"/><StrRes Name="clCirRefNotAllow" Text="Circular child reference is not allowed"/><StrRes Name="clDupName" Text="Duplicate n' + 
'ame"/><StrRes Name="clErrorInExp" Text="Error in Calc expression:"/><StrRes Name="expMtm" Text="Timeout expired"/><StrRes Name="erInvalidImg" Text="In' + 
'valid image format"/><StrRes Name="ReportTitle" Text="ReportTitle"/><StrRes Name="ReportSummary" Text="ReportSummary"/><StrRes Name="PageHeader" Text=' + 
'"PageHeader"/><StrRes Name="PageFooter" Text="PageFooter"/><StrRes Name="Header" Text="Header"/><StrRes Name="Footer" Text="Footer"/><StrRes Name="Mas' + 
'terData" Text="MasterData"/><StrRes Name="DetailData" Text="DetailData"/><StrRes Name="SubdetailData" Text="SubdetailData"/><StrRes Name="Data4" Text=' + 
'"Data4"/><StrRes Name="Data5" Text="Data5"/><StrRes Name="Data6" Text="Data6"/><StrRes Name="GroupHeader" Text="GroupHeader"/><StrRes Name="GroupFoote' + 
'r" Text="GroupFooter"/><StrRes Name="Child" Text="Child"/><StrRes Name="ColumnHeader" Text="ColumnHeader"/><StrRes Name="ColumnFooter" Text="ColumnFoo' + 
'ter"/><StrRes Name="Overlay" Text="Overlay"/><StrRes Name="2_5_interleaved" Text="2_5_interleaved"/><StrRes Name="2_5_industrial" Text="2_5_industrial' + 
'"/><StrRes Name="2_5_matrix" Text="2_5_matrix"/><StrRes Name="Code39" Text="Code39"/><StrRes Name="Code39 Extended" Text="Code39 Extended"/><StrRes Na' + 
'me="Code128A" Text="Code128A"/><StrRes Name="Code128B" Text="Code128B"/><StrRes Name="Code128C" Text="Code128C"/><StrRes Name="Code93" Text="Code93"/>' + 
'<StrRes Name="Code93 Extended" Text="Code93 Extended"/><StrRes Name="MSI" Text="MSI"/><StrRes Name="PostNet" Text="PostNet"/><StrRes Name="Codebar" Te' + 
'xt="Codebar"/><StrRes Name="EAN8" Text="EAN8"/><StrRes Name="EAN13" Text="EAN13"/><StrRes Name="UPC_A" Text="UPC_A"/><StrRes Name="UPC_E0" Text="UPC_E' + 
'0"/><StrRes Name="UPC_E1" Text="UPC_E1"/><StrRes Name="UPC Supp2" Text="UPC Supp2"/><StrRes Name="UPC Supp5" Text="UPC Supp5"/><StrRes Name="EAN128A" ' + 
'Text="EAN128A"/><StrRes Name="EAN128B" Text="EAN128B"/><StrRes Name="EAN128C" Text="EAN128C"/><StrRes Name="rpEditRep" Text="Edit Report..."/><StrRes ' + 
'Name="rpEditAlias" Text="Edit Fields Aliases..."/><StrRes Name="rave0" Text="Rave Import"/><StrRes Name="rave1" Text="The Rave file doesn''t contain TR' + 
'aveReport items."/><StrRes Name="rave2" Text="The Rave file contains %d reports. Each report will be converted to one fr3 file. Choose a directory whe' + 
're fr3 files will be saved. Note that only the last report will be opened in the designer."/><StrRes Name="rave3" Text="Cannot create %s."/><StrRes Na' + 
'me="rave4" Text="Report %s, page %s."/></Resources>' + 
' ';

initialization
  frxResources.AddXML(resXML);

end.
