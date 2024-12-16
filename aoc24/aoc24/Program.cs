using aoc24.Components;
using Microsoft.AspNetCore.Http.Features;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddRazorComponents()
    .AddInteractiveServerComponents();


// Configure Kestrel for larger request bodies
builder.WebHost.ConfigureKestrel(serverOptions =>
{
	serverOptions.Limits.MaxRequestBodySize = 256 * 1024; // 256 KB
});

// Configure Form Options for larger form data
builder.Services.Configure<FormOptions>(options =>
{
	options.ValueLengthLimit = 256 * 1024; // 256 KB
	options.MultipartBodyLengthLimit = 256 * 1024; // 256 KB
	options.MultipartHeadersLengthLimit = 256 * 1024; // 256 KB
});

// SignalR Configuration for larger message sizes
builder.Services.AddSignalR(options =>
{
	options.MaximumReceiveMessageSize = 256 * 1024; // 256 KB
});

// Build the application
var app = builder.Build();


// Add middleware and configure pipeline after Build()
app.Use((context, next) =>
{
	if (context.Request.Path.StartsWithSegments("/_blazor"))
	{
		context.Features.Set<IHttpMaxRequestBodySizeFeature>(null);
	}
	return next();
});

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
	app.UseExceptionHandler("/Error", createScopeForErrors: true);
	// The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
	app.UseHsts();
}

app.UseHttpsRedirection();

app.UseStaticFiles();
app.UseAntiforgery();

app.MapRazorComponents<App>()
	.AddInteractiveServerRenderMode();

app.Run();