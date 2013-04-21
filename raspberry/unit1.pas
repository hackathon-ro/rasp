unit Unit1; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, mysql50conn, FileUtil, Forms, Controls, Graphics, Dialogs,
  StdCtrls, ExtCtrls, IpHtml, httpsend;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    edtGamma: TEdit;
    edtWind: TEdit;
    Memo1: TMemo;
    Panel1: TPanel;
    Panel2: TPanel;
    tmrWind: TTimer;
    tmrPC: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure tmrPCTimer(Sender: TObject);
    procedure tmrWindTimer(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  Form1: TForm1;
  fGamma:text;
  fWind:text;

implementation

{$R *.lfm}

{ TForm1 }

function HTTPPost(const URL, URLData:string; const Data:TStream):boolean;
var http:THTTPSend;
begin
     http:=THTTPSend.Create;
     try
        http.document.write(Pointer(URLData)^,Length(URLData));
        result:=HTTP.HTTPMethod('POST',URL);
     finally
       http.free;
     end;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
    try
      tmrPC.enabled:=true;
      assignFile(fGamma,edtGamma.text);reset(fGamma);
      memo1.lines.add('Connected to '+edtGamma.text);
    except
      memo1.lines.add('Failed to connect to '+edtGamma.text);
    end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
    try
      tmrWind.enabled:=true;
      assignFile(fWind,edtWind.text);reset(fWind);
      memo1.lines.add('Connected to '+edtWind.text);
    except
      memo1.lines.add('Failed to connect to '+edtWind.text);
    end;
end;

procedure TForm1.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
    try
     CloseFile(fGamma);
     CloseFile(fWind);
    except
    end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
end;

procedure TForm1.tmrPCTimer(Sender: TObject);
var s:string;
    dez,res:string;
    Data:TStream;
begin
    tmrPC.Enabled:=false;;
     readln(fGamma,s);
     if s<>'' then begin
       // # 32 dez/1s<LF>CR>
       memo1.lines.add('Geiger received: '+s);
       try
              while (s<>'') and (s[1]<>'#') do delete(s,1,1);
              while (s<>'') and ((s[1]='#') or (s[1]=' ')) do delete(s,1,1);
              dez:=copy(s,1,pos(' ',s)-1);
              delete(s,1,pos('/',s));
              while(s<>'') and (s[1]=' ') do delete(s,1,1);
              res:=copy(s,1,pos('s',s)-1);
              s:='http://hackathon.capel.ro/submit_dez.php?dez='+dez+'&res='+res;
              //memo1.lines.add(s);
              if HTTPPost(s,'',Data) then begin
                 Panel2.color:=clLime;
                 Panel2.Caption:='Data sent';
              end else begin
                  panel2.color:=clRed;
                  panel2.caption:='Can''t send data';
              end;
       finally
       end;
     end;
     if memo1.lines.count>10000 then memo1.lines.clear;
     tmrPC.enabled:=true;

end;

procedure TForm1.tmrWindTimer(Sender: TObject);
var s:string;
    spd:string;
    Data:TStream;
begin
    tmrWind.Enabled:=false;;
     readln(fWind,s);
     if s<>'' then begin
       // *22.72m/s,81.8km/h
       // * No wind
       memo1.lines.add('Wind received: '+s);
       try
              if pos('No wind',s)<>0 then spd:='0' else begin
                 while (s<>'') and (s[1]<>'*') do delete(s,1,1);
                 while (s<>'') and ((s[1]='*') or (s[1]=' ')) do delete(s,1,1);
                 spd:=copy(s,1,pos('m',s)-1);
              end;
              s:='http://hackathon.capel.ro/submit_ane.php?spd='+spd;
              //memo1.lines.add(s);
              if HTTPPost(s,'',Data) then begin
                 Panel2.color:=clLime;
                 Panel2.Caption:='Data sent';
              end else begin
                  panel2.color:=clRed;
                  panel2.caption:='Can''t send data';
              end;
       finally
       end;
     end;
     tmrWind.Enabled:=true;

end;

end.
