
% Read dns.in 
% -------------------
f = fopen('dns.in','r');
line = fgetl(f); i=find(line=='='); 
ny=str2num(line(i(1)+1:i(2)-3)); nx=str2num(line(i(2)+1:i(3)-3)); nz=str2num(line(i(3)+1:end));
line = fgetl(f); i=find(line=='='); 
alfa0=str2num(line(i(1)+1:i(2)-6)); beta0=str2num(line(i(2)+1:end));
line = fgetl(f); i=find(line=='='); 
ymin=str2num(line(i(1)+1:i(2)-5)); ymax=str2num(line(i(2)+1:i(3)-2)); a=str2num(line(i(3)+1:end));
nxc=3*floor(nx/2)-1; while ~fftfit(nxc); nxc=nxc+1; end; nxc=2*nxc;
nzc=3*floor(nz)-1; while ~fftfit(nzc); nzc=nzc+1; end
fclose(f);

% Read parameters in gkedata.cpl
% --------------------
f = fopen('../gkedata.cpl','r');
line = ''; while ~contains(line,'uLx1'); line=fgetl(f); end
i=find(line=='='); uLx1=str2num(line(i(1)+1:i(2)-5)); uLx2=str2num(line(i(2)+1:end-1));
i=find(line=='='); uLz1=str2num(line(i(1)+1:i(2)-5)); uLz2=str2num(line(i(2)+1:end-1));
fclose (f);

% Define grid
% ---------------------
x=linspace(0,2*pi/alfa0,nxc);
y=tanh(a*(2*(-1:ny+1)/ny-1))/tanh(a)+1;
z=linspace(0,2*pi/beta0,nzc);

L_x = 2 * pi / ( alfa0 ); 
L_z = 2 * pi / ( beta0 );
dz = L_z / nzc;    
dx = L_x / nxc; 

% Define indices 
% (this is relevant for the undersampling)
% ----------------------
mx=0; ix=0;
while ix<nxc/2
    imx(mx+1)=ix; mx=mx+1; ix=ix+(ix*dx<=uLx1)+(ix*dx>uLx1).*((ix*dx>uLx2)*4+4);
end
if imx(mx)<nxc/2; imx(mx+1)=nxc/2; mx=mx+1; end
for i=1:mx-2; imx(mx+i)=mod((nxc-imx(mx-i)),nxc); end; mx=2*mx-2;
mz=0; iz=0;
while iz<nzc/2
    imz(mz+1)=iz; mz=mz+1; iz=iz+(iz*dz<=uLz1)+(iz*dz>uLz1).*((iz*dz>uLz2)*4+4);
end
if imz(mz)<nzc/2; imz(mz+1)=nzc/2; mz=mz+1; end
for i=1:mz-2; imz(mz+i)=mod((nzc-imz(mz-i)),nzc); end; mz=2*mz-2;

% Define the startpos array
% ----------------------
%
% gke.bin is a C-ordered 
% ARRAY(0..startpos(ny DIV 2 +1)-1,0..mx-1,0..mz-1) OF GKETERMS
% (see gkedata.cpl for the definition of GKETERMS)
% 
% the second and third index in the array are the streamwise and spanwise 
% separation, while the first is a flattened index corresponding to the
% touple [iy1,iy2], whith iy1=-1:ny/2 and iy2=y1:ny-y1. iy1 and iy2 are the
% two wall-normal indices at which we evaluate the structure function. Remember
% that ry = y(iy2)-y(iy1) and Yc=0.5*(y(iy1)+y(iy2)). In this way, 
% startpos(iy+i) will be the index pointing to the touple iy1=iy and
% iy2=iy+i, if available.
%
% Of course, the indices used n this comment are as in the CPL code, here
% we are in MATLAB and indices always have to start from 1
%
startpos = zeros(round(ny/2)+3,1); startpos(2:end) = cumsum(ny-2*(-1:ny/2)+1);

% Load the GKE
% -----------------------
% 
% This will load only the GKE for ry=0 and rx=0
f = fopen('./gke.bin','r');
gkei=zeros(6,mz,ny/2+2); IX=1; IZ=1;
for iy=-1:ny/2
    IY=iy+2;
    fseek( f, 8*(6 * mz * mx * ( startpos( IY ) ) + 6 * mz * ( IX - 1 ) + 6 * ( IZ - 1 )) ,'bof');
    gkei(:,:,IY)=reshape(fread(f,6*mz,'double'),[6,mz]);

end
fclose(f);

% Plot a term of the GKE
% ------------------------
figure()
k=6; % 1: phiRx, 2: phiRy, 3: phiRz, 4: phiC, 5: <duidui>, 6: xi 
labels={'\phi_{r_x}','\phi_{r_y}','\phi_{r_z}','\phi_C', '<\delta u_i \delta u_i>', '\xi'};
pcolor(z(imz+1), y(2:ny/2+2), squeeze(gkei(k,:,2:end))'); shading interp
hold on
contour(z(imz+1), y(2:ny/2+2), squeeze(gkei(k,:,2:end))',[0,0],'k--');
set(gca(),'Layer','top')
xlabel('r_z')
ylabel('Y')
title(labels{k});
colorbar();

drawnow nocallbacks
