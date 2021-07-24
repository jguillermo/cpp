VERSION 5.00
Object = "{86CF1D34-0C5F-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCT2.OCX"
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form CrearItem 
   Caption         =   "CREAR PRODUCTO"
   ClientHeight    =   10665
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   13665
   LinkTopic       =   "Form1"
   ScaleHeight     =   10665
   ScaleWidth      =   13665
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text6 
      DataField       =   "codigo"
      DataSource      =   "Adodc1"
      Height          =   495
      Left            =   10560
      TabIndex        =   37
      Text            =   "Text6"
      Top             =   2520
      Width           =   615
   End
   Begin VB.TextBox Text5 
      DataField       =   "FechaDeCompra"
      DataSource      =   "Adodc2"
      Height          =   495
      Left            =   11280
      TabIndex        =   36
      Text            =   "Text5"
      Top             =   3000
      Width           =   615
   End
   Begin MSAdodcLib.Adodc Adodc2 
      Height          =   495
      Left            =   11880
      Top             =   3000
      Width           =   1695
      _ExtentX        =   2990
      _ExtentY        =   873
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   2
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   1
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   $"CrearItem.frx":0000
      OLEDBString     =   $"CrearItem.frx":0093
      OLEDBFile       =   ""
      DataSourceName  =   ""
      OtherAttributes =   ""
      UserName        =   ""
      Password        =   ""
      RecordSource    =   "compras"
      Caption         =   "Ado2"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   495
      Left            =   11880
      Top             =   2520
      Width           =   1680
      _ExtentX        =   2963
      _ExtentY        =   873
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   2
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   1
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   $"CrearItem.frx":0126
      OLEDBString     =   $"CrearItem.frx":01B9
      OLEDBFile       =   ""
      DataSourceName  =   ""
      OtherAttributes =   ""
      UserName        =   ""
      Password        =   ""
      RecordSource    =   "producto"
      Caption         =   "Ado1"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin VB.TextBox Text4 
      DataField       =   "Id"
      DataSource      =   "Adodc1"
      Height          =   495
      Left            =   11160
      TabIndex        =   35
      Text            =   "Text4"
      Top             =   2520
      Width           =   735
   End
   Begin VB.TextBox Text3 
      DataField       =   "Id"
      DataSource      =   "Adodc2"
      Height          =   495
      Left            =   10560
      TabIndex        =   34
      Text            =   "Text3"
      Top             =   3000
      Width           =   735
   End
   Begin VB.TextBox Text2 
      DataField       =   "codigo"
      DataSource      =   "Adodc2"
      Height          =   495
      Left            =   9840
      TabIndex        =   33
      Text            =   "Text2"
      Top             =   3000
      Width           =   735
   End
   Begin VB.TextBox Text1 
      DataField       =   "TipoDeDocumento"
      DataSource      =   "Adodc2"
      Height          =   495
      Left            =   9120
      TabIndex        =   32
      Text            =   "Text1"
      Top             =   3000
      Width           =   735
   End
   Begin VB.Frame frcompra 
      Caption         =   "COMPRA"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   6135
      Left            =   120
      TabIndex        =   1
      Top             =   3600
      Width           =   11655
      Begin VB.CommandButton Cmd4 
         Caption         =   "&Cancelar"
         Height          =   735
         Left            =   4920
         TabIndex        =   31
         Top             =   5160
         Width           =   3495
      End
      Begin VB.CommandButton Cmd3 
         Caption         =   "&Guardar"
         Height          =   615
         Left            =   480
         TabIndex        =   30
         Top             =   5160
         Width           =   3495
      End
      Begin MSComCtl2.MonthView fecha 
         Height          =   2370
         Left            =   5280
         TabIndex        =   14
         Top             =   360
         Width           =   2595
         _ExtentX        =   4577
         _ExtentY        =   4180
         _Version        =   393216
         ForeColor       =   -2147483630
         BackColor       =   -2147483633
         Appearance      =   1
         MonthBackColor  =   8454016
         StartOfWeek     =   23134210
         TitleBackColor  =   12640511
         TitleForeColor  =   192
         CurrentDate     =   39526
      End
      Begin VB.Frame Frame2 
         Caption         =   "Frame2"
         Height          =   1815
         Left            =   360
         TabIndex        =   13
         Top             =   3120
         Width           =   10335
         Begin VB.TextBox TxtPrecioLima 
            DataField       =   "PrecioTotalSolesLima"
            DataSource      =   "Adodc2"
            Height          =   495
            Left            =   2760
            TabIndex        =   26
            Top             =   1080
            Width           =   2175
         End
         Begin VB.TextBox TxtCanCmprada 
            DataField       =   "CantCompr"
            DataSource      =   "Adodc2"
            Height          =   495
            Left            =   2760
            TabIndex        =   25
            Top             =   360
            Width           =   2175
         End
         Begin VB.Label lbPrecioSugerido 
            Caption         =   "Precio Sugerido"
            Height          =   495
            Left            =   5520
            TabIndex        =   28
            Top             =   960
            Width           =   4215
         End
         Begin VB.Label lbPrecioUnitario 
            Caption         =   "Precio Unitario"
            Height          =   375
            Left            =   6240
            TabIndex        =   27
            Top             =   480
            Width           =   3855
         End
         Begin VB.Label Label9 
            Caption         =   "Precio Total en Soles Lima"
            Height          =   615
            Left            =   240
            TabIndex        =   24
            Top             =   1080
            Width           =   2415
         End
         Begin VB.Label Label8 
            Caption         =   "Cantidad Comprada"
            Height          =   495
            Left            =   240
            TabIndex        =   23
            Top             =   360
            Width           =   2415
         End
      End
      Begin VB.Frame Frame1 
         Caption         =   "Tipo Y Numero de Documento"
         Height          =   2055
         Left            =   600
         TabIndex        =   12
         Top             =   480
         Width           =   4215
         Begin VB.TextBox TxtNumDoc 
            DataField       =   "NumeroDeDocumento"
            DataSource      =   "Adodc2"
            Height          =   615
            Left            =   2040
            TabIndex        =   20
            Top             =   1080
            Width           =   1935
         End
         Begin VB.OptionButton Option3 
            Caption         =   "SN"
            Height          =   375
            Left            =   240
            TabIndex        =   18
            Top             =   1320
            Width           =   1215
         End
         Begin VB.OptionButton Option2 
            Caption         =   "FACTURA"
            Height          =   375
            Left            =   240
            TabIndex        =   17
            Top             =   840
            Width           =   1215
         End
         Begin VB.OptionButton Option1 
            Caption         =   "BOLETA"
            Height          =   375
            Left            =   240
            TabIndex        =   16
            Top             =   360
            Width           =   1215
         End
         Begin VB.Label lbNumDoc 
            Caption         =   "Numero de "
            Height          =   495
            Left            =   2040
            TabIndex        =   19
            Top             =   360
            Width           =   1935
         End
      End
      Begin VB.Label lbFecha 
         DataSource      =   "Adodc2"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   18
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   8520
         TabIndex        =   15
         Top             =   960
         Width           =   2295
      End
   End
   Begin VB.Frame frproducto 
      Caption         =   "PRODUCTO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3135
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   8775
      Begin VB.CommandButton cmd5 
         Caption         =   "&Cambiar Precio de Venta"
         Height          =   495
         Left            =   6120
         TabIndex        =   38
         Top             =   1920
         Width           =   1815
      End
      Begin VB.TextBox TxtUnidad 
         DataField       =   "unidad"
         DataSource      =   "Adodc1"
         Height          =   285
         Left            =   1800
         TabIndex        =   29
         Top             =   2520
         Width           =   3255
      End
      Begin VB.CommandButton Cmd2 
         Caption         =   "&Cancelar"
         Height          =   495
         Left            =   6120
         TabIndex        =   22
         Top             =   1200
         Width           =   1815
      End
      Begin VB.CommandButton Cmd1 
         Caption         =   "&Guardar"
         Height          =   615
         Left            =   6120
         TabIndex        =   21
         Top             =   360
         Width           =   1815
      End
      Begin VB.TextBox TxtPrecioDeVenta 
         DataField       =   "PrecioDeVenta"
         DataSource      =   "Adodc1"
         Height          =   285
         Left            =   1800
         TabIndex        =   10
         Top             =   2040
         Width           =   3255
      End
      Begin VB.TextBox TxtProductoEspecifico 
         DataField       =   "ProductoEspecifico"
         DataSource      =   "Adodc1"
         Height          =   285
         Left            =   1800
         TabIndex        =   9
         Top             =   1560
         Width           =   3255
      End
      Begin VB.TextBox TxtGerupoProducto 
         DataField       =   "GrupoProducto"
         DataSource      =   "Adodc1"
         Height          =   285
         Left            =   1800
         TabIndex        =   8
         Top             =   1080
         Width           =   3255
      End
      Begin VB.TextBox TxtCodigo 
         Height          =   285
         Left            =   1800
         TabIndex        =   7
         Top             =   480
         Width           =   3255
      End
      Begin VB.Label Label5 
         Caption         =   "Unidad"
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   2640
         Width           =   735
      End
      Begin VB.Label Label4 
         Caption         =   "Precio de venta"
         Height          =   255
         Left            =   240
         TabIndex        =   5
         Top             =   2040
         Width           =   1215
      End
      Begin VB.Label Label3 
         Caption         =   "Producto Especifico"
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   1560
         Width           =   1455
      End
      Begin VB.Label Label2 
         Caption         =   "Grupo producto"
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   1080
         Width           =   1335
      End
      Begin VB.Label Label1 
         Caption         =   "Codigo"
         Height          =   255
         Left            =   360
         TabIndex        =   2
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.CommandButton cmdbusca 
      Caption         =   "BUSCA CODIGO"
      Default         =   -1  'True
      BeginProperty Font 
         Name            =   "Algerian"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1455
      Left            =   9600
      TabIndex        =   11
      Top             =   360
      Width           =   2055
   End
End
Attribute VB_Name = "CrearItem"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim Tipo_accion As Boolean
Dim Tipo_accion2 As Boolean
Dim Registro_actual As Variant
Dim codigotemporal As String

Private Sub Cmd1_Click()
If Cmd1.Caption = "&Crear nueva compra" Then
bloquea2 False
 Cmd1.Enabled = True
Cmd2.Enabled = True
 Adodc2.Recordset.AddNew
 Tipo_accion2 = True
  Cmd1.Enabled = False
Cmd2.Enabled = False

Text2.Text = codigotemporal
Else

 On Error GoTo Imprevisto
        Adodc1.Recordset.Update
      
   
      Cmd1.Caption = "&Crear nueva compra"
 Cmd2.Caption = "&Salir"
      

       
        Exit Sub
Imprevisto:
        MsgBox Err.Description
End If
End Sub

Private Sub Cmd2_Click()
If Cmd2.Caption = "&Salir" Then
End
Else
Adodc1.Recordset.CancelUpdate
        Adodc1.Recordset.Requery
        If Not Tipo_accion Then
            Adodc1.Recordset.Bookmark = Registro_actual
        End If
bloquea1 True
bloquea2 True
cmdbusca.Enabled = True
        End If
End Sub

Private Sub Cmd3_Click()
On Error GoTo Imprevisto
        Adodc2.Recordset.Update
        Cmd3.Enabled = False
        Cmd4.Enabled = False
       
        cmd5.Enabled = True
        cmdbusca.Enabled = True
        Cmd2.Enabled = True
        Exit Sub
Imprevisto:
        MsgBox Err.Description
End Sub

Private Sub Cmd4_Click()
Adodc2.Recordset.CancelUpdate
        Adodc2.Recordset.Requery
        If Not Tipo_accion2 Then
            Adodc2.Recordset.Bookmark = Registro_actual
        End If
bloquea2 True

cmdbusca.Enabled = True
       
End Sub

Private Sub cmd5_Click()
If cmd5.Caption = "&Cambiar Precio de Venta" Then


Tipo_accion = False
       TxtPrecioDeVenta.Locked = False
       
       
        Registro_actual = Adodc1.Recordset.Bookmark
        '*******************************************
        bloquea2 True
        
        Cmd2.Caption = "&Cancelar"
        cmd5.Enabled = True
        
        Cmd1.Enabled = False
         cmd5.Caption = "&Grabar"
Else

 On Error GoTo Imprevisto
        Adodc1.Recordset.Update
      
   
 cmdbusca.Enabled = True
 
 Cmd2.Caption = "&Salir"
 cmd5.Caption = "&Cambiar Precio de Venta"

       
        Exit Sub
Imprevisto:
        MsgBox Err.Description
End If
End Sub

Private Sub cmdbusca_Click()
Dim Xcod As String * 8
 Xcod = InputBox("Ingrese el código a buscar", "Busqueda de Clientes [Control ADO]")
    codigotemporal = Xcod
   'If Len(Xcod) >= 9 Or Len(Xcod) <= 7 Then
   'MsgBox "codigo de 8 cifras "
    '  Exit Sub
'End If
 TxtCodigo.Text = Xcod
        codigotemporal = Xcod
      
  With Adodc1.Recordset
        .MoveFirst
        .Find "codigo='" + Trim(Xcod) + "'"
        If .EOF Then
            If MsgBox("No se encontro el codigo ingresado : " + Trim(Xcod) + "   desea crear un nuevo producto", vbYesNo) = 6 Then
        bloquea1 False
             Tipo_accion = True
               Adodc1.Recordset.AddNew
            Text6 = Xcod
               cmdbusca.Enabled = False
               Else
                .MoveFirst
              End If
         Else
         Cmd1.Caption = "&Crear nueva compra"
         Cmd2.Caption = "&Salir"
        Cmd1.Enabled = True
        Cmd2.Enabled = True
        cmd5.Enabled = True
        cmdbusca.Enabled = False
        End If
    End With
 
End Sub

Private Sub fecha_DateClick(ByVal DateClicked As Date)
Text5.Text = CStr(fecha.Value)
lbFecha = fecha.Value
End Sub

Private Sub Form_Load()
bloquea1 True
bloquea2 True

End Sub
Sub bloquea1(var As Boolean)
TxtCodigo.Locked = True
TxtGerupoProducto.Locked = var
TxtProductoEspecifico.Locked = var
TxtPrecioDeVenta.Locked = var
TxtUnidad.Locked = var
Cmd1.Enabled = Not var
Cmd2.Enabled = Not var
cmd5.Enabled = Not var
End Sub
Sub bloquea2(var As Boolean)
TxtNumDoc.Locked = var
TxtPrecioLima.Locked = var
TxtCanCmprada.Locked = var
fecha.Enabled = Not var
Option1.Enabled = Not var
Option2.Enabled = Not var
Option3.Enabled = Not var
Cmd3.Enabled = Not var
Cmd4.Enabled = Not var
End Sub

Private Sub Option1_Click()
Text1.Text = "B"
lbNumDoc.Caption = "Numero de Boleta"
End Sub

Private Sub Option2_Click()
Text1.Text = "F"
lbNumDoc.Caption = "Numero de Factura"
End Sub

Private Sub Option3_Click()
Text1.Text = "SN"
lbNumDoc.Caption = "Numero de Documento"
End Sub

Private Sub TxtPrecioLima_Change()
If Not Val(TxtCanCmprada.Text) = 0 Then
lbPrecioUnitario.Caption = "Precio Unitario  =  " + Str(Val(TxtPrecioLima.Text) / Val(TxtCanCmprada.Text))
lbPrecioSugerido.Caption = "Precio sugerido al 50p del FOB  =  " + Str((Val(TxtPrecioLima.Text) / Val(TxtCanCmprada.Text)) * 1.15 * 1.5)

End If
End Sub
