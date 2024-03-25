unit frxRegChartLaz;

{$I frx.inc}

interface

procedure Register;

implementation

uses
SysUtils,
Classes ,Graphics, Controls, Forms,
PropEdits, LazarusPackageIntf, LResources,
frxChartLaz;

procedure Register;
begin
  RegisterComponents('FastReport 5', [TfrxChartObject]);
end;

initialization

{$INCLUDE frxRegChartLaz.lrs}

end.

